// =========================================================================================
// Adnd1 - rules/oaiaijutsu.h
// OA SURPRISE AND IAIJUTSU, printed capture p. 218 - the dueling draw
// doctrine round
// census 602 -> 603.
//
// pinned from the 2018 print capture - the sole surviving pass from Chapter 9
// onward, per the R679 provenance shift. The iaijutsu proficiency grants
// special opportunities to surprise opponents through the lightning speed of
// the draw, but the modifier lives only in special situations: the noncombat
// encounter that suddenly erupts into attack. The printed example walks the
// kneel-beside negotiation with weapons sheathed - the situation grows tense,
// the NPC attacks without warning, and surprise rolls are made to see if both
// sides are prepared. THE MODIFIER: a -1 applied to the surprise die roll of
// the character WITHOUT the proficiency when only one side is trained; when
// BOTH are trained the -1 applies to BOTH rolls - the startling speed of the
// trained weapon into action. THE EXCEPTIONS: no modifier when weapons are
// already drawn, none when the opponent has reason to expect an attack - the
// modifier only applies when an otherwise peaceful situation erupts into
// bloody conflict, especially from an unexpected quarter. The prose codifies
// per the R431 calculus
//
// the gap census after this round: 133 closed, 102 open - the Surprise and
// Iaijutsu box flips (census 602 -> 603); NEXT - R681: the Initiative
// Modifiers (capture p. 218), prefix dis (verify free at the landing), audit
// "R681 OA initiative modifiers audit", include after rules/oaiaijutsu.h
//
namespace rules {

// ---- the iaijutsu modifier pins ----

// the iaijutsu surprise modifier - a -1 applied to the surprise die roll of
// the character WITHOUT the proficiency when the iaijutsu-trained character
// suddenly draws and attacks, reflecting the startling speed of the trained
// draw (print capture p. 218)
inline int diqIaijutsuSurpriseModifier()
    { return 1; }

// the both-trained case - when BOTH characters have iaijutsu proficiency, the
// -1 modifier applies to BOTH surprise die rolls, the two rolls each carrying
// the draw-speed penalty (print capture p. 218)
inline int diqIaijutsuBothTrappedCount()
    { return 2; }

// ---- the iaijutsu doctrine pins ----

// the scope clause - because of the nature of the skill the modifier only
// applies in special situations: a character in a noncombat encounter
// suddenly drawing his weapon to attack (print capture p. 218)
inline bool diqIaijutsuSpecialSituationsOnly()
    { return true; }

// the asymmetric case - if one character has iaijutsu proficiency and the
// other does not, the -1 modifier applies to the surprise die roll of the
// character without the proficiency, the trained character escaping
// unpenalized (print capture p. 218)
inline bool diqIaijutsuUntrainedCarriesPenalty()
    { return true; }

// the dueling surprise rolls - when the peaceful situation erupts, surprise
// rolls are made to see if both sides are prepared, the kneel-beside
// sheathed-weapons negotiation the printed example (print capture p. 218)
inline bool diqIaijutsuBothSidesRollSurprise()
    { return true; }

// the drawn-weapons exception - no modifier is applied when weapons are
// already drawn (print capture p. 218)
inline bool diqIaijutsuNilWhenWeaponsDrawn()
    { return true; }

// the expected-attack exception - no modifier is applied when the opponent
// has reason to expect an attack (print capture p. 218)
inline bool diqIaijutsuNilWhenAttackExpected()
    { return true; }

// the eruption clause - the iaijutsu modifier only applies when an otherwise
// peaceful situation erupts into bloody conflict, especially from an
// unexpected quarter (print capture p. 218)
inline bool diqIaijutsuPeacefulEruptionOnly()
    { return true; }

}   // namespace rules
