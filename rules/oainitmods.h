// =========================================================================================
// Adnd1 - rules/oainitmods.h
// OA INITIATIVE MODIFIERS, printed capture pp. 218-219 - the quickness
// doctrine round
// census 603 -> 604.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. The doctrine frame: Oriental Adventures characters live
// and rely on their quickness and speed, some developing improved chances of
// striking the crucial first blow. THE CHARACTER-ONLY CLAUSE: when modifiers
// apply to only some of the characters involved, the initiative roll is still
// made only once for each side; those with modifiers apply their modifier to
// the die roll for their side BUT for the actions of that character only -
// the round may thus divide into more than two phases of attacks. THE TIE
// RULES: a tie (modified or unmodified) is not rerolled - all act in the same
// instant, and damage or spell effects are not applied to a same-initiative
// character until he has completed his action, the normal results then
// landing. THE PRINTED EXAMPLE: the 1st-level kensai, samurai and shukenja
// party rolls the 3, the hostile samurai the 4 - the kensai (modified 4)
// strikes in the same instant as the NPCs, then the remaining player
// characters; a hypothetical NPC kensai (modified 5) would strike first, then
// the simultaneous remaining NPCs and the PC kensai, then the survivors. THE
// LANDSLIDE RULE: when one side beats even the highest modified initiative of
// the other, the winning side completes all attacks in whatever order desired
// before the other side begins. The prose codifies per the R431 calculus
//
// the gap census after this round: 134 closed, 101 open - the Initiative
// Modifiers box flips (census 603 -> 604); NEXT - R682: the Combat Procedures
// with the missile fire from horseback doctrine (capture p. 219), prefix div
// (verify free at the landing - dis and dit are TAKEN, the disease and ditch
// call families), audit "R682 OA combat procedures audit", include after
// rules/oainitmods.h
//
namespace rules {

// ---- the initiative roll and example pins ----

// the initiative roll is made only once for each side - the two rolls of the
// round, one per side, even when modifiers apply to only some of the
// characters involved (print capture pp. 218-219)
inline int diuOAInitiativeRollsPerRound()
    { return 2; }

// the printed example PC side roll - the kensai, samurai and shukenja party,
// all 1st level, rolling the 3 against the hostile samurai group (print
// capture pp. 218-219)
inline int diuOAExamplePCSideRoll()
    { return 3; }

// the printed example NPC side roll - the hostile samurai group rolling the
// 4, winning the round against the PC 3 (print capture pp. 218-219)
inline int diuOAExampleNPCSideRoll()
    { return 4; }

// the printed example kensai modified initiative - the 4, carrying him into
// the same instant as the winning NPC side, the kensai and the NPCs striking
// first together (print capture pp. 218-219)
inline int diuOAExampleKensaiModified()
    { return 4; }

// the printed example hypothetical NPC kensai modified initiative - the 5,
// striking first ahead of everyone, followed by the simultaneous remaining
// NPCs and the PC kensai, then the surviving player characters (print capture
// pp. 218-219)
inline int diuOAExampleNpcKensaiModified()
    { return 5; }

// ---- the initiative doctrine pins ----

// the doctrine frame - characters in the Oriental Adventures world live and
// rely on their quickness and speed, some having developed their speed to the
// point of improved chances of striking the crucial first blow (print capture
// pp. 218-219)
inline bool diuOAQuicknessDoctrine()
    { return true; }

// the once-per-side rule - when modifiers to the initiative apply to only
// some of the characters involved, the initiative roll is still made only
// once for each side (print capture pp. 218-219)
inline bool diuOAInitiativeOncePerSide()
    { return true; }

// the character-only clause - those characters with modifiers apply their
// modifier to the die roll for their side BUT for the actions of that
// character only (print capture pp. 218-219)
inline bool diuOAModifierCharacterOnly()
    { return true; }

// the phase division - thus the actions of an initiative round may be divided
// into more than two phases of attacks (print capture pp. 218-219)
inline bool diuOAPhasesExceedTwo()
    { return true; }

// the tie rule - when the initiative (modified or unmodified) results in a
// tie, the die is not rerolled (print capture pp. 218-219)
inline bool diuOATieNotRerolled()
    { return true; }

// the tie simultaneity - all characters or creatures are assumed to be acting
// in the same instant (print capture pp. 218-219)
inline bool diuOATieSimultaneous()
    { return true; }

// the tie resolution - damage done or the effects of spells are not applied
// to a character with the same initiative until he has completed his action;
// as soon as he has finished, he suffers the normal results of actions
// against him (print capture pp. 218-219)
inline bool diuOATieEffectsAfterAction()
    { return true; }

// the landslide rule - when the initiative of one side is greater than even
// the highest modified initiative of the other side, all characters on the
// winning side complete their attacks in whatever order is desired, their
// actions completed before those of the other side begin (print capture pp.
// 218-219)
inline bool diuOAWinnerOrderUnimportant()
    { return true; }

}   // namespace rules
