// =========================================================================================
// Adnd1 - rules/oapsychicduel.h
// OA THE PSYCHIC DUEL, printed capture pp. 222-223 - the wills contest round
// census 609 -> 610.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE FRAME: the psychic duel a type of mental combat
// practiced by any character race or class, requiring no psionic talent - the
// test of the wills, the invisible fight revealed by the grimace, the eyelid,
// the tic; the wise man admitting defeat before it occurs. THE CIRCUMSTANCES:
// only on or by intelligent human or humanoid creatures, strictly one-on-one
// - never between friends (3 points of honor), never with crossed weapons,
// never under outside attack: the pre-battle challenge or the swaggering
// bully. THE RESOLUTION: the round spent within 10 feet concentrating the
// will, each saving throw vs. death - the kensai +2 against non-kensai; one
// makes one wins, both fail inconclusive, both make locked for another round;
// the breaker the loser, his nerve broken. THE HONOR: 2 points beating a
// higher level, 1 the equal, none the lower. THE LOSER: retreat losing the
// equal honor, or attack at -1 on initiative, to hit and saves throughout, no
// surprise - both sides prepared. The prose codifies per the R431 calculus
//
// the gap census after this round: 140 closed, 95 open - the Psychic Duel box
// flips (census 609 -> 610); NEXT - R688: the Martial Arts doctrine opener
// (capture pp. 223-224), prefix djb (verify free at the landing), audit "R688
// OA martial arts opener audit", include after rules/oapsychicduel.h
//
namespace rules {

// ---- the psychic duel number pins ----

// the psychic duel range - the characters spend the round within 10 feet of
// each other, concentrating their will (print capture p. 222)
inline int djaOAPsychicDuelRangeFeet()
    { return 10; }

// the kensai duel bonus - kensai characters have a bonus of +2 to the saving
// throw vs. death roll when facing non-kensai characters (print capture p.
// 222)
inline int djaOAPsychicDuelKensaiBonus()
    { return 2; }

// the friends dishonor - the duel never used between friends or companions,
// such an action being highly insulting and dishonorable for both, 3 points
// of honor (print capture p. 222)
inline int djaOAPsychicDuelFriendsHonor()
    { return 3; }

// the higher-level honor award - the winner of a psychic duel gains 2 points
// of honor if his opponent is of a higher experience level than himself
// (print capture p. 223)
inline int djaOAPsychicDuelHigherLevelHonor()
    { return 2; }

// the equal-level honor award - if the two are equal level, the winner gains
// 1 point of honor (print capture p. 223)
inline int djaOAPsychicDuelEqualLevelHonor()
    { return 1; }

// the loser attack penalty - if the loser attacks regardless of the outcome,
// he is -1 on his initiative, to hit, and saving throw rolls throughout the
// ensuing battle (print capture p. 223)
inline int djaOAPsychicDuelLoserAttackPenalty()
    { return -1; }

// ---- the psychic duel doctrine pins ----

// the doctrine frame - the psychic duel a type of mental combat practiced by
// any character race or class, requiring no psionic talent, a test of the
// wills of the duelists - their courage, skill and determination, the
// invisible fight revealed by a faint grimace, the flicker of an eyelid, or
// the tic of a muscle (print capture p. 222)
inline bool djaOAPsychicDuelDoctrine()
    { return true; }

// the anyone clause - although the psychic duel can be attempted by anyone,
// it can only be done under special circumstances (print capture p. 222)
inline bool djaOAPsychicDuelAnyoneMayTry()
    { return true; }

// the human-or-humanoid gate - it can only be used on or by intelligent
// creatures of human or humanoid races (print capture p. 222)
inline bool djaOAPsychicDuelHumanOnly()
    { return true; }

// the one-on-one rule - it is strictly a one-on-one duel, a single character
// facing off against another (print capture p. 222)
inline bool djaOAPsychicDuelOneOnOne()
    { return true; }

// the friends exclusion - it is never used between friends or companions,
// such an action being highly insulting and dishonorable for both (print
// capture p. 222)
inline bool djaOAPsychicDuelNeverFriends()
    { return true; }

// the crossed-weapons exclusion - the characters cannot have crossed weapons
// before during the encounter (print capture p. 222)
inline bool djaOAPsychicDuelNoCrossedWeapons()
    { return true; }

// the outside-attack exclusion - neither can it be used if they are attacked
// by others during the course of the psychic duel, not in the heat of a
// furious battle but in a challenge before the battle, or on a swaggering
// bully in the street (print capture p. 222)
inline bool djaOAPsychicDuelNoOutsideAttacks()
    { return true; }

// the resolution roll - each character rolls a saving throw vs. death (print
// capture p. 222)
inline bool djaOAPsychicDuelSaveVersusDeath()
    { return true; }

// the split outcome - if one character makes a successful saving throw and
// the other does not, the successful character has won the duel (print
// capture p. 222)
inline bool djaOAPsychicDuelOneMakesOneWins()
    { return true; }

// the inconclusive outcome - if both characters fail the saving throw, the
// duel is inconclusive and neither wins (print capture p. 222)
inline bool djaOAPsychicDuelBothFailInconclusive()
    { return true; }

// the continuation outcome - if both characters make the saving throw, they
// are locked in the mental battle and the duel continues for another round
// (print capture p. 222)
inline bool djaOAPsychicDuelBothMakeContinue()
    { return true; }

// the nerve-break rule - should one player break off the duel and attack
// before it is resolved, he is the loser, his nerve has broken (print capture
// p. 222)
inline bool djaOAPsychicDuelBreakerLoses()
    { return true; }

// the loser retreat option - the loser may retreat, losing points of honor
// equal to those gained by the victor (print capture p. 223)
inline bool djaOAPsychicDuelLoserRetreat()
    { return true; }

// the loser attack option - the loser can attack regardless of the outcome of
// the psychic duel (print capture p. 223)
inline bool djaOAPsychicDuelLoserMayAttack()
    { return true; }

// the no-surprise rule - no surprise roll is made after the duel, since both
// sides are prepared (print capture p. 223)
inline bool djaOAPsychicDuelNoSurprise()
    { return true; }

// the lower-level rule - if the loser is of lower level, the winner gains no
// honor for the duel (print capture p. 223)
inline bool djaOAPsychicDuelLowerLevelNoHonor()
    { return true; }

}   // namespace rules
