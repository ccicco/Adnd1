// =========================================================================================
// Adnd1 - rules/oacreatestyle.h
// OA CREATING A STYLE, printed capture pp. 225-227 - the style-construction
// round
// census 612 -> 613.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE FRAME: the DM encouraged to create new styles taught
// by NPC masters, the general characteristics chosen then the values, terms
// and abilities selected from the lists. THE THREE FORMS: hard - muscles and
// bones, direct, offensive; soft - the inner power, fluid and circular,
// defensive, the attacker's force against him, attacking only after the
// commitment; combined - the best of each, physical balanced with psychic;
// all using the unusual weapons. THE PRINCIPAL METHOD: the most common
// fighting method, every style incorporating moves from other methods - the
// single form the certain defeat. THE MECHANICS: one form and one method per
// style; the mods totaled - the AC from the 10, the attacks style-specific,
// the damage rounded up to the die (6 the d6, 4 the d4, 5 the d6), the body
// part free; the 1d4-minus-two weapons of the martial-arts-only list. THE
// MANEUVERS: the intensive study, the combat cost (one or more attacks) and
// the movement cost (no attacks), the method organization with the hard/soft
// identity and the crossover; the 1d8 roll of the principal method or the
// Mental and Physical Training, the 1-3 roll of the other methods - the
// arsenal of tactics; the ranking progression from 1 up, the higher learned
// only beneath; the gradual learning; the Mental and Physical Training
// learnable in any style. The prose codifies per the R431 calculus
//
// the gap census after this round: 143 closed, 92 open - the Creating a Style
// box flips (census 612 -> 613); NEXT - R691: Table 69 the martial style
// combinations grid (capture p. 226), prefix dje (verify free at the
// landing), audit "R691 OA style combinations audit", include after
// rules/oacreatestyle.h
//
namespace rules {

// ---- the style construction number pins ----

// the style armor class base - the AC Mod. of the form and the method
// totaled, the number subtracted from 10 to get the armor class of the style
// (print capture p. 226)
inline int djdOACreateACBase()
    { return 10; }

// the weapons-taught die - the DM rolls 1d4 and subtracts two from the
// result, the number of weapons taught under the style (print capture p. 226)
inline int djdOACreateWeaponsDie()
    { return 4; }

// the weapons-taught shift - the two subtracted from the 1d4 roll (print
// capture p. 226)
inline int djdOACreateWeaponsShift()
    { return 2; }

// the first maneuver roll - roll 1d8, the number of special maneuvers chosen
// from the principal method of the style or from the Mental and Physical
// Training lists (print capture p. 227)
inline int djdOACreateManeuverFirstDie()
    { return 8; }

// the second maneuver roll - a roll of 1-3 made to find the number of
// maneuvers chosen from other methods (or again the Mental and Physical
// Training category) (print capture p. 227)
inline int djdOACreateManeuverSecondDie()
    { return 3; }

// ---- the style construction doctrine pins ----

// the creation frame - in addition to the common styles the DM is encouraged
// to create new styles taught by various NPC masters, a style created by
// choosing the general characteristics then selecting values, terms and
// abilities from the lists given in the text (print capture p. 225)
inline bool djdOACreateDoctrine()
    { return true; }

// the hard form - emphasizing the use of the muscles and bones for power,
// very direct movements, generally offensive, stressing the attack (print
// capture p. 225)
inline bool djdOACreateHardForm()
    { return true; }

// the soft form - relying more on the inner power of the character, the
// movements fluid and circular, generally more defensive, diverting the
// attacker with his own force against him and attacking only after the enemy
// has committed himself, the training more mentally oriented (print capture
// p. 225)
inline bool djdOACreateSoftForm()
    { return true; }

// the combined form - using the best practices from each, the circular and
// gentle defensive movements combined with swift and direct attacks, the
// physical training balanced with the psychic (print capture p. 225)
inline bool djdOACreateCombinedForm()
    { return true; }

// the weapons clause - all styles can make use of a number of unusual weapons
// (print capture p. 225)
inline bool djdOACreateUnusualWeapons()
    { return true; }

// the principal method choice - the fighting method most commonly used in the
// style, the character more often than not using it when attacking, each
// method describing the most common means of attack (print capture p. 225)
inline bool djdOACreatePrincipalMethod()
    { return true; }

// the other-methods rule - every style incorporates moves from other methods,
// since reliance on a single form would certainly mean defeat (print capture
// p. 225)
inline bool djdOACreateOtherMethods()
    { return true; }

// the selection rule - the DM must select one form and one principal method
// for each style (print capture p. 226)
inline bool djdOACreateOneFormOneMethod()
    { return true; }

// the attacks rule - the #AT Mod. of the form and the method totaled is the
// number of attacks allowed in a melee round when fighting in this style,
// applying to no other style nor when fighting with normal weapons (print
// capture p. 226)
inline bool djdOACreateAttacksStyleSpecific()
    { return true; }

// the damage rule - the Damage Mod. of the form and the method totaled,
// rounded up to the nearest die size used in the game: a total of 6 the 1d6,
// of 4 the 1d4, of 5 the 1d6 - the basic damage done when fighting in the
// style (print capture p. 226)
inline bool djdOACreateDamageRounding()
    { return true; }

// the body part rule - the listed part or parts most commonly used, kicking
// the feet, throwing the whole body; so long as the body part is unbound or
// free to move the character can still attack effectively with the style
// (print capture p. 226)
inline bool djdOACreateBodyPartFree()
    { return true; }

// the weapons selection - the weapons selected from those that can be used in
// martial arts only (print capture p. 226)
inline bool djdOACreateWeaponsList()
    { return true; }

// the creation order - finally the DM must determine the special maneuvers
// used by the style (print capture p. 226)
inline bool djdOACreateManeuversLast()
    { return true; }

// the maneuvers frame - actions and abilities requiring intensive study and
// skill to learn, giving the user greater-than-normal results; some attempted
// during a fight (Flying Kick, One Finger), others constant abilities always
// in effect (Ironskin, Blind Fighting) (print capture pp. 226-227)
inline bool djdOAManeuversIntensiveStudy()
    { return true; }

// the combat maneuver cost - combat maneuvers risky, failure often leaving
// the character in an exposed or dangerous position, the maneuver costing one
// or more of his attacks for the melee round (print capture p. 227)
inline bool djdOAManeuversCombatCost()
    { return true; }

// the movement maneuver cost - a movement maneuver counts as movement,
// preventing the character from making any attacks that round unless the
// maneuver notes otherwise (print capture p. 227)
inline bool djdOAManeuversMovementCost()
    { return true; }

// the organization - all maneuvers organized according to the principal
// method of fighting used, kicking covering kicks, movement the leaps,
// tumbles, dives and acrobatics; each maneuver identified as hard, soft or
// hard/soft, matching the general classification of the style, the crossover
// not prevented (print capture p. 227)
inline bool djdOAManeuversMethodOrganized()
    { return true; }

// the second-roll scope - the 1-3 roll finding the maneuvers chosen from
// other methods, all styles usually incorporating a few maneuvers from other
// methods to provide the character an arsenal of tactics (print capture p.
// 227)
inline bool djdOAManeuversSecondRollOthers()
    { return true; }

// the ranking rule - the maneuvers ranked by difficulty, the lower the number
// the easier to learn and execute; when selecting there must be a progression
// from 1 on up, not within a single method, more than one at the same level
// allowed - a style beginning Circle Kick (1), Flying Kick (2), All-Around
// Sight (2), ending Backward Kick (3); a higher difficulty maneuver learned
// only if those beneath it are already learned (print capture p. 227)
inline bool djdOAManeuversRanking()
    { return true; }

// the gradual rule - special maneuvers not gained immediately upon learning
// the style, requiring extra training and learned gradually (print capture p.
// 227)
inline bool djdOAManeuversGradualLearning()
    { return true; }

// the Mental and Physical Training category - maneuvers learnable in any
// style because of the methods of practice and discipline of the training
// (print capture p. 227)
inline bool djdOAMentalPhysicalAnyStyle()
    { return true; }

}   // namespace rules
