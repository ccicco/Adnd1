// =========================================================================================
// Adnd1 - rules/oahorsefire.h
// OA COMBAT PROCEDURES, printed capture p. 219 - the mounted bowfire round
// census 604 -> 605.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE DOCTRINE FRAME: the mounted bowman is an integral
// part of the armies and fighting styles of the Oriental lands, the warriors
// firing great longbows at a full gallop. THE STANDING-HORSE FREEDOM: any
// character can use a missile weapon from the back of an unmoving horse - no
// particular skill. THE HORSEMANSHIP GATE: firing from a moving horse
// requires the horsemanship proficiency, the bow needing two hands so the
// horse is guided with the knees; the DM can rule extremely rough ground
// forces the reins, preventing bowfire. THE RATE: horseback fire is half the
// normal rate - 2/1 becomes 1/1, 3/1 becomes 3/2 - with to-hit penalties
// based on the speed of the animal, listed on Table 67. The prose codifies
// per the R431 calculus
//
// the gap census after this round: 135 closed, 100 open - the Combat
// Procedures box flips (census 604 -> 605); NEXT - R683: Table 67 the
// horseback bowfire modifiers (capture p. 220), prefix diw (verify free at
// the landing - diu and div TAKEN by the R681/R682 call families), audit
// "R683 OA horseback bowfire modifiers audit", include after
// rules/oahorsefire.h
//
namespace rules {

// ---- the mounted rate of fire pins ----

// the rate of fire from horseback is half what the character is normally
// allowed - the halving divisor of the mounted shots (print capture p. 219)
inline int divOAHorsebackRateDivisor()
    { return 2; }

// the printed rate conversion - the 2/1 rate of fire becoming 1/1 from
// horseback, the halved shots of the low example (print capture p. 219)
inline int divOAExampleMountedShotsLow()
    { return 1; }

// the printed rate conversion numerator - the 3/1 rate of fire becoming 3/2
// from horseback, the shots of the second example (print capture p. 219)
inline int divOAExampleMountedNumHigh()
    { return 3; }

// the printed rate conversion denominator - the 3/2 of the halved 3/1 rate,
// the rounds span of the second example (print capture p. 219)
inline int divOAExampleMountedDenHigh()
    { return 2; }

// the two-hands rule - firing the bow requires two hands, the mounted bowman
// with the horsemanship proficiency guiding the horse with his knees (print
// capture p. 219)
inline int divOABowfireHandsRequired()
    { return 2; }

// ---- the horseback bowfire doctrine pins ----

// the doctrine frame - the mounted bowman is an integral part of the armies
// and fighting styles of the Oriental lands, the warriors refining the art
// until they fire great longbows at a full gallop (print capture p. 219)
inline bool divOAMountedBowmanDoctrine()
    { return true; }

// the unmoving-horse freedom - any character can use a missile weapon from
// the back of an unmoving horse, taking no particular skill (print capture p.
// 219)
inline bool divOAUnmovingHorseAnyCharacter()
    { return true; }

// the horsemanship gate - when firing from the back of a moving horse, the
// character must have the horsemanship proficiency (print capture p. 219)
inline bool divOAMovingHorseNeedsHorsemanship()
    { return true; }

// the knees-guidance clause - the bowfire requiring two hands forces the
// mounted character to guide the horse with his knees (print capture p. 219)
inline bool divOAKneesGuidance()
    { return true; }

// the DM rough-ground clause - the DM can rule that extremely rough areas of
// ground (rocky slopes, thick underbrush) require the character to handle the
// reins, preventing bowfire (print capture p. 219)
inline bool divOADMRoughGroundBlocksBowfire()
    { return true; }

// the speed-based penalties - the mounted character also suffers penalties on
// his chance to hit, based on the speed of the animal, listed on Table 67
// (print capture p. 219)
inline bool divOASpeedBasedToHitPenalty()
    { return true; }

}   // namespace rules
