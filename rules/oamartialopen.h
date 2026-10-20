// =========================================================================================
// Adnd1 - rules/oamartialopen.h
// OA MARTIAL ARTS OPENER, printed capture pp. 223-224 - the doctrine prose
// round
// census 610 -> 611.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE FRAME: the martial arts a combat style unique to
// these lands - the body into a weapon, hands, feet, legs, arms, head,
// defeating the better armed and armored through rigorous training and deep
// discipline. THE THREE REASONS: the nature-forces philosophy (living in
// harmony, the tools intruding upon it), the religious divestment (only the
// inner qualities permanent), the social pressure (the weapon-restriction
// edicts, torture and execution, the commoners unarmed). THE ART:
// regularized, studied, guiding the student to self-perfection. THE
// PROLIFERATION: every land its own styles against the local weapons and the
// beasts, each master his own moves - the school challenges the spectator
// events. THE GOAL: the fighter trained to avoid being hurt - the defensive,
// aggressive and weapon-master schools; the near-infinite forms; the unarmed
// misnomer with the tui-fu; the styles defined by their effects, the five
// characteristics grouping into a style. The prose codifies per the R431
// calculus
//
// the gap census after this round: 141 closed, 94 open - the Martial Arts
// prose box flips (census 610 -> 611); NEXT - R689: Table 68 the common
// martial styles grid (capture p. 224), prefix djc (verify free at the
// landing), audit "R689 OA common martial styles audit", include after
// rules/oamartialopen.h
//
namespace rules {

// ---- the martial arts opener number pins ----

// the five style characteristics - the martial arts classified by number of
// attacks, damage, armor class, principal attack form and special maneuvers,
// the elements grouped together forming a style (print capture p. 224)
inline int djbOAMartialStyleChars()
    { return 5; }

// ---- the martial arts opener doctrine pins ----

// the doctrine frame - the martial arts a style of combat that never
// developed significantly in the rest of the AD&D world, the body developed
// into a useful weapon defeating opponents supposedly better armed and
// armored (print capture p. 223)
inline bool djbOAMartialArtsDoctrine()
    { return true; }

// the whole-body rule - the unarmed fighter uses his entire body - hands,
// feet, legs, arms, head - any part turned into a weapon, through rigorous
// training demanding great physical and mental discipline (print capture p.
// 223)
inline bool djbOAMartialWholeBodyWeapon()
    { return true; }

// the training clause - the unarmed fighter must learn to anticipate actions,
// harden his body, block out pain, and summon energies from deep within
// himself, a deep commitment on the part of the character (print capture p.
// 223)
inline bool djbOAMartialTrainingDiscipline()
    { return true; }

// the nature philosophy - the belief in the forces of nature surrounding and
// charging everything with hidden energies, the character part of them
// drawing upon them, living in harmony; tools effective but outside the
// harmony, intruding upon it - understanding one's own body one factor
// leading to unarmed skill (print capture p. 223)
inline bool djbOAMartialNaturePhilosophy()
    { return true; }

// the religious strand - material possessions of little real worth, the
// devout divesting themselves of the desire for the material world, only the
// inner qualities permanent and positively known; reliance upon a weapon
// reliance upon the material world (print capture p. 223)
inline bool djbOAMartialReligiousDivestment()
    { return true; }

// the social strand - severe edicts restricting weapon ownership in conquered
// lands and troublesome provinces, punishments including torture and
// execution, the commoners finding other ways to defend themselves (print
// capture p. 223)
inline bool djbOAMartialSocialPressure()
    { return true; }

// the regularization - the skills widely practiced and honorable, the styles
// and training practices regularized, careful study of scientific principles
// and religious concepts, unarmed fighting an art guiding the student to
// self-perfection when practiced diligently and correctly (print capture p.
// 223)
inline bool djbOAMartialRegularizedArt()
    { return true; }

// the proliferation - every land its own styles countering the locally
// favored weapons and studying the natural styles of the beasts, each master
// his own moves and methods - two masters of the same style easily fighting
// in entirely different forms (print capture p. 223)
inline bool djbOAMartialStyleProliferation()
    { return true; }

// the school challenges - arguments and challenges over which style was
// better quite common, the fighters of different schools seeking supremacy,
// often spectator events with hundreds of interested onlookers (print capture
// p. 224)
inline bool djbOAMartialSchoolChallenges()
    { return true; }

// the primary goal - at the lowest level the martial arts train the fighter
// in the use of his body, the primary goal that he can avoid being hurt
// (print capture p. 224)
inline bool djbOAMartialPrimaryGoalAvoidHurt()
    { return true; }

// the defensive schools - some styles mainly defensive, diverting or avoiding
// the attack (print capture p. 224)
inline bool djbOAMartialDefensiveStyles()
    { return true; }

// the aggressive schools - other styles more aggressive, their masters
// believing that attacking is the best way to protect oneself (print capture
// p. 224)
inline bool djbOAMartialAggressiveStyles()
    { return true; }

// the weapon-master schools - others demanding the fighter learn and master
// many different weapons to understand their use (print capture p. 224)
inline bool djbOAMartialWeaponMasterStyles()
    { return true; }

// the forms variety - punches, blocks, kicks, pushes, throws, holds, locks
// and dodges, a near infinite variety of moves depending mainly on the style
// learned (print capture p. 224)
inline bool djbOAMartialFormsVariety()
    { return true; }

// the misnomer - unarmed combat also a misnomer: students often expected to
// learn common and unusual weapons, their use taught only as part of a
// particular martial arts style - the tui-fu foolish in peasant hands but
// deadly in the hands of a master of martial arts (print capture p. 224)
inline bool djbOAMartialUnarmedMisnomer()
    { return true; }

// the rules fit - the martial arts designed to fit within the AD&D rules, the
// styles defined by their effects - number of attacks, damage, armor class
// and principal attack form, the special maneuvers coming only with
// dedication and training (print capture p. 224)
inline bool djbOAMartialRulesFit()
    { return true; }

// the style names - styles given descriptive or poetic names: animal names
// (Snake, Monkey, Tiger), poetic names (Eight Drunken Fairies), descriptive
// names (Empty Hand, Springing Legs, Eight Fists), each identifying a
// particular style (print capture p. 224)
inline bool djbOAMartialStyleNames()
    { return true; }

// the style use identity - styles further identified by their use, some
// highly defensive relying on the inner power of the user, others aggressive
// stressing form and channeled power in hard and sudden attacks (print
// capture p. 224)
inline bool djbOAMartialStyleUseIdentity()
    { return true; }

}   // namespace rules
