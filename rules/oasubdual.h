// =========================================================================================
// Adnd1 - rules/oasubdual.h
// OA SUBDUING OPPONENTS, printed capture pp. 221-222 - the subdual doctrine
// round
// census 608 -> 609.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE DOCTRINE: defeating an opponent without killing him -
// the shukenja class normally forbidden from killing, the prisoners and
// hostages useful only alive. THE GATES: subdual only against creatures of at
// least low Intelligence, the genius-rated subdued only by voluntary
// surrender, any creature or NPC in scope - but a player character NEVER
// forced, the surrender the player's choice. THE MECHANICS: the fight-start
// declaration, the blunt edge, flat, haft, butt, pommel or hilt striking,
// each blow normal but only 1/4 costing hit points, the 3/4 recorded
// separately as subdual - the surrender when subdual exceeds the STARTING hit
// points; any normal-damage attack voiding all subdual points. THE SURRENDER:
// stop fighting and drop weapons; the exactable oath with the secret honor
// roll or the save versus death - compliance or the show of agreement; the
// captive seeking the first escape. The prose codifies per the R431 calculus
//
// the gap census after this round: 139 closed, 96 open - the Subduing
// Opponents box flips (census 608 -> 609); NEXT - R687: The Psychic Duel
// (capture pp. 222-223), prefix dja (verify free at the landing - diz the
// LAST di- prefix taken, the dj- family opens), audit "R687 OA psychic duel
// audit", include after rules/oasubdual.h
//
namespace rules {

// ---- the subdual damage split pins ----

// the subdual hit-point loss numerator - damage from each blow determined
// normally but only 1/4 of it causing a loss of hit points (print capture p.
// 222)
inline int dizOASubdualHitLossNum()
    { return 1; }

// the subdual hit-point loss denominator - the quarter share of normal damage
// that costs hit points (print capture p. 222)
inline int dizOASubdualHitLossDen()
    { return 4; }

// the subdual damage numerator - the remaining 3/4 of each blow recorded as
// subdual damage (print capture p. 222)
inline int dizOASubdualDamageNum()
    { return 3; }

// the subdual damage denominator - the three-quarter share of each blow
// carried as subdual damage, recorded separately from the hit points lost
// (print capture p. 222)
inline int dizOASubdualDamageDen()
    { return 4; }

// ---- the subdual doctrine pins ----

// the doctrine frame - sometimes desirable to defeat an opponent without
// killing him, particularly true of the shukenja character class normally
// forbidden from killing, and of the need to take prisoners or a hostage,
// both useful only when alive (print capture p. 221)
inline bool dizOASubdualDoctrine()
    { return true; }

// the intelligence gate - subdual can only be used against creatures with at
// least a modicum of Intelligence, at least the low Intelligence rating
// (print capture p. 221)
inline bool dizOASubdualIntelligenceGate()
    { return true; }

// the genius clause - those of genius Intelligence or greater can only be
// subdued if they voluntarily decide to surrender, knowing too well the fate
// that awaits most prisoners (print capture p. 221)
inline bool dizOASubdualGeniusVoluntary()
    { return true; }

// the scope rule - subdual can be used against any kind of creature or NPC
// (print capture p. 221)
inline bool dizOASubdualAnyCreature()
    { return true; }

// the player-choice rule - a player character can never be forced into
// submission; player characters may decide to surrender but the choice is
// left to the player (print capture p. 221)
inline bool dizOASubdualPCNeverForced()
    { return true; }

// the declaration rule - players must declare any subdual attempt at the
// beginning of the fight, the attackers then assumed to be striking with the
// blunt edge, flat, haft, butt, pommel or hilt of their weapon (print capture
// p. 222)
inline bool dizOASubdualMustDeclare()
    { return true; }

// the normal-damage roll - damage from each blow determined normally, only
// the quarter share costing hit points (print capture p. 222)
inline bool dizOASubdualDamageNormal()
    { return true; }

// the separate record - subdual damage recorded separately from the hit
// points lost (print capture p. 222)
inline bool dizOASubdualRecordedSeparately()
    { return true; }

// the surrender threshold - the being subdued and surrendering when the
// subdual damage exceeds the total STARTING hit points (not the current hit
// points) of the creature or character (print capture p. 222)
inline bool dizOASubdualSurrenderAtStartHP()
    { return true; }

// the voiding rule - if any attack is made on the being for normal damage
// after the declaration to subdue, the creature will not surrender: all
// subdual points disappear and the creature is fought normally (print capture
// p. 222)
inline bool dizOASubdualNormalDamageVoids()
    { return true; }

// the subdued state - a subdued creature must stop fighting and drop its
// weapons (print capture p. 222)
inline bool dizOASubduedMustStop()
    { return true; }

// the oath mechanics - if the players can communicate, they can exact an oath
// (a task or promise); the DM secretly rolls against the creature's honor if
// it has honor points, or makes a saving throw versus death - equal or less
// than the honor, or a failed save, means compliance; otherwise a show of
// agreeing while hoping for vengeance later (print capture p. 222)
inline bool dizOASubdualOathCheck()
    { return true; }

// the captive clause - alternatively the victor can keep the creature
// captive, it seeking the first opportunity to escape, humble and docile only
// as long as the captors maintain the upper hand (print capture p. 222)
inline bool dizOASubdualCaptiveEscape()
    { return true; }

}   // namespace rules
