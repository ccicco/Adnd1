// =========================================================================================
// Adnd1 - rules/oatrain.h
// OA MENTAL AND PHYSICAL TRAINING, printed capture pp. 232-233 - the
// any-style training round
// census 616 -> 617.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE CATEGORY: the training maneuvers belong to no
// principal method - learned by practitioners of any method or style,
// reflecting the superb control over mind and body. THE MANEUVERS: the
// Meditation with all the shukenja powers, the shukenja and kensai spending
// no slot for what they have; the All-Around Sight constant, the opponents on
// all sides detected but the invisible unseen, never struck from behind nor
// penalized from a back attack; the Mental Resistance constant, the +2
// against the charm, illusion and hold; the Blind Fighting constant, only a
// -1 in darkness or blindness or against the invisible, but the silence spell
// with any of them leaving the character effectively blind again; the
// Ironskin, the muscles hardened like iron for the AC 2 better - only
// unarmored; the Levitation the rarest, one turn of concentration to negate
// the weight, then five feet per round up, down or sideways, no actions, the
// broken concentration a fall, one round of rest owed. THE STUNNING AND
// INCAPACITATING: every style's chance against a man-sized opponent - the
// UNMODIFIED 20 on the to hit roll forcing the save vs. paralyzation; the
// save made meaning no stun or incapacity but the normal damage kept; the
// save failed meaning the die roll compared to the hit dice or level - the
// roll LESS the 1d6 melee round stun, the roll GREATER the 1-3 hour
// incapacity, an equal roll the stun per the printed lizard man example (the
// 2 rolled equal to the 2+1 dice); the +4 or greater on the hit dice treated
// as one extra die. The grid mechanics codified per the R431 calculus
//
// the gap census after this round: 147 closed, 88 open - the Mental and
// Physical Training box flips (census 616 -> 617); NEXT - R695: the Learning
// Martial Arts with Multiple Styles and Combining Styles prose (capture pp.
// 233-235), prefix dji (verify free at the landing), audit "R695 OA learning
// martial arts audit", include after rules/oatrain.h
//
namespace rules {

// ---- the mental and physical training maneuvers ----

// the Training category - the maneuvers do not belong to the principal
// methods, learned by practitioners of any method or style in the course of
// training (print capture p. 232)
inline bool djhTrainAnyStyle()
    { return true; }

// the Meditation - all the powers of meditation as explained under the
// shukenja character description (print capture p. 232)
inline bool djhMeditationShukenjaPowers()
    { return true; }

// the Meditation exemption - shukenja and kensai, who already have the
// ability, need not spend a proficiency slot on this maneuver (print capture
// p. 232)
inline bool djhMeditationFreeSlot()
    { return true; }

// the All-Around Sight - constantly in effect, detecting opponents on all
// sides provided they are not invisible (print capture p. 232)
inline bool djhAllAroundSightConst()
    { return true; }

// the All-Around Sight protection - the character can never be struck from
// behind nor suffer a penalty from a back attack (print capture p. 232)
inline bool djhAllAroundNoBackAttack()
    { return true; }

// the Mental Resistance saving throw bonus - +2 on all saves against mental
// attacks including charm, illusion and hold spells (print capture p. 233)
inline int djhMentalResSaveBonus()
    { return 2; }

// the Mental Resistance - constantly in effect, the will toughened by the
// mental exercises and ordeals of the training (print capture p. 233)
inline bool djhMentalResConst()
    { return true; }

// the Blind Fighting penalty - only a -1 when fighting in darkness, blinded
// or against invisible opponents (print capture p. 233)
inline int djhBlindFightPenalty()
    { return 1; }

// the Blind Fighting - constantly in effect, the senses trained under the
// blindfold and in darkened rooms (print capture p. 233)
inline bool djhBlindFightConst()
    { return true; }

// the Blind Fighting limit - any of the blindness causes combined with a
// silence spell render the character effectively blind again (print capture
// p. 233)
inline bool djhBlindFightSilenceRule()
    { return true; }

// the Ironskin armor class bonus - the muscles hardened like iron, AC
// improved by 2 only when wearing no other armor (print capture p. 233)
inline int djhIronskinACBonus()
    { return 2; }

// the Ironskin limit - the AC improvement applies only when the character
// wears no other type of armor (print capture p. 233)
inline bool djhIronskinUnarmoredOnly()
    { return true; }

// the Levitation - the rarest of the maneuvers, the utmost of concentration
// and mental discipline negating the character's own weight (print capture p.
// 233)
inline bool djhLevRarest()
    { return true; }

// the Levitation concentration - one turn of concentration required before
// the body's weight is overcome (print capture p. 233)
inline int djhLevConcTurns()
    { return 1; }

// the Levitation movement - up, down or sideways at five feet per round
// (print capture p. 233)
inline int djhLevMoveFt()
    { return 5; }

// the Levitation rest - one round of rest owed upon completion before any
// other action (print capture p. 233)
inline int djhLevRestRounds()
    { return 1; }

// the Levitation limit - no actions while levitating, a broken concentration
// dropping the character to the ground (print capture p. 233)
inline bool djhLevNoActions()
    { return true; }

// ---- the stunning and incapacitating rules ----

// the Stunning and Incapacitating trigger - an unmodified 20 on the martial
// arts to hit roll forces the victim's save vs. paralyzation (print capture
// p. 233)
inline int djhStunHitRoll()
    { return 20; }

// the stun duration die - 1d6 melee rounds when the die roll is less than the
// victim's hit dice or level (print capture p. 233)
inline int djhStunDie()
    { return 6; }

// the incapacitation minimum - 1-3 hours when the die roll is greater than
// the hit dice or level, the OCR artifact t-3 resolved as 1-3 per the printed
// lizard man example (print capture p. 233)
inline int djhIncapHoursMin()
    { return 1; }

// the incapacitation maximum - the 3 of the 1-3 hours (print capture p. 233)
inline int djhIncapHoursMax()
    { return 3; }

// the extra-die threshold - creatures with a +4 or greater on their hit dice
// are treated as having one extra die for the stun or incapacity calculation
// (print capture p. 233)
inline int djhExtraDieHDBonus()
    { return 4; }

// the Stunning and Incapacitating scope - all styles have the chance against
// a man-sized opponent (print capture p. 233)
inline bool djhStunManSizedOnly()
    { return true; }

// the Stunning and Incapacitating trigger - the UNMODIFIED 20 on the to hit
// roll, not a modified one (print capture p. 233)
inline bool djhStunUnmodifiedOnly()
    { return true; }

// the stun save - the victim is allowed a saving throw vs. paralyzation
// (print capture p. 233)
inline bool djhStunSavePara()
    { return true; }

// the successful stun save - the victim not stunned or incapacitated but
// still taking the normal damage of the attack (print capture p. 233)
inline bool djhStunSaveSuccessDamage()
    { return true; }

// the stun or incapacity calculus - the die roll compared to the victim's hit
// dice or level: the roll less means the 1d6 round stun, the roll greater the
// 1-3 hour incapacity, an equal roll the stun per the printed lizard man
// example (print capture p. 233)
inline bool djhStunCompareHD()
    { return true; }

// the +4 hit dice rule - creatures with a +4 or greater on their hit dice
// treated as having one extra die for this calculation (print capture p. 233)
inline bool djhExtraDieRule()
    { return true; }

}   // namespace rules
