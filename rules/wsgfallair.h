// =========================================================================================
// Adnd1 - rules/wsgfallair.h
// The WSG AIRBORNE FALL CHANCE AND RIDING PROFICIENCY pins, R461: the Chapter
// 5 closer - the to-fall-or-not-to-fall system (the 0% base on smooth level
// flight at the full normal rate; the reduction ladder: the full-body strap,
// the lower-body strap, the proficiency, the saddle, the stirrups, the
// per-point ability rule over the 12 threshold with the 18 strength cap; the
// increase ladder: the free hands, the overload, the faster-than-normal
// flight, the unwilling mount, the inclement weather, the not-level flight,
// the below-12 per-point rule, the wind ladder over the 30-mph threshold; the
// every-three-turns check with the landing restart and the once-per-round
// exception) and the airborne riding proficiency (the per-category slots, the
// hands-free negation, the no-control rule, the ideal-conditions feats, the
// nonproficient auto-fail).
// census 385 -> 386.
//
// The read: the OCR session 8d6a65a0, pdf pages 49-50 = printed 48-49,
// cross-checked against the second OCR copy - the two read word-for-word
// identical. The sign convention is pinned by the p. 49 text: the proficiency
// enjoys a -50% modifier that effectively negates the +50% for riding without
// holding on, so the first six table rows are reductions and the last seven
// are increases over the 0% base.
//
namespace rules {

// ---- the fall chance base ----

// The base chance of falling: 0 percent - the mount giving a smooth and level
// flight at its full normal movement rate.
inline int wfaBaseFallChancePct()
    { return 0; }

// A character always has a chance of falling from the back of an airborne
// mount unless he is securely fastened to the creature.
inline bool wfaChanceUnlessFastened()
    { return true; }

// Sitting in a saddle (or some other kind of seat) without being actually
// attached to the creature increases the chance.
inline bool wfaSaddleNoAttachmentWorse()
    { return true; }

// Riding without a saddle or some means of retaining the hold on the mount
// increases the chance further.
inline bool wfaNoSaddleWorseStill()
    { return true; }

// ---- the fall chance reductions ----

// Reduction: the rider's entire body (upper and lower) securely strapped onto
// the mount.
inline int wfaStrapFullBodyPct()
    { return -200; }

// Reduction: the rider's lower body only securely strapped onto the mount.
inline int wfaStrapLowerBodyPct()
    { return -150; }

// Reduction: the rider has proficiency in airborne riding in the appropriate
// category.
inline int wfaAirborneProfPct()
    { return -50; }

// Reduction: the rider is using a saddle.
inline int wfaSaddlePct()
    { return -10; }

// Reduction: the saddle is equipped with stirrups.
inline int wfaStirrupsPct()
    { return -10; }

// Reduction per point of rider's dexterity above 12 and rider's strength
// above 12.
inline int wfaPerAbilityAbove12Pct()
    { return -2; }

// The ability-score threshold the per-point fall modifiers key on.
inline int wfaAbilityModThreshold()
    { return 12; }

// Strength reads as 18 at most for the per-point fall modifier.
inline int wfaStrengthCap()
    { return 18; }

// ---- the fall chance increases ----

// Increase per point of rider's dexterity below 12 and rider's strength below
// 12.
inline int wfaPerAbilityBelow12Pct()
    { return 2; }

// Increase: the rider is not strapped onto the mount and not holding on -
// hands free or carrying something.
inline int wfaFreeHandsPct()
    { return 50; }

// Increase: the mount is carrying more than its normal load limit.
inline int wfaOverloadPct()
    { return 20; }

// Increase: the mount is moving faster than its full normal movement rate -
// diving, dodging, performing combat maneuvers.
inline int wfaFasterThanNormalPct()
    { return 20; }

// Increase: the mount's demeanor is unwilling or rebellious and the creature
// is not charmed, subdued or similarly influenced.
inline int wfaUnwillingMountPct()
    { return 20; }

// Increase: inclement weather - sandstorm, heavy precipitation, or worse.
inline int wfaInclementWeatherPct()
    { return 20; }

// Increase: the mount is not flying level - sharp turns, loops, and the like.
inline int wfaNotFlyingLevelPct()
    { return 10; }

// The wind-velocity threshold the per-mph fall modifier keys on.
inline int wfaWindThresholdMph()
    { return 30; }

// Increase per mph of wind velocity greater than the threshold.
inline int wfaPerWindMphAbove30Pct()
    { return 1; }

// ---- the fall check cadence ----

// The fall chance is checked at least once every three turns while airborne -
// assuming smooth and normal flight.
inline int wfaFallCheckEveryTurns()
    { return 3; }

// Under bad weather, an uncooperative mount or abrupt changes of direction
// and speed, a check may be called for as often as once per round.
inline int wfaBadConditionsPerRounds()
    { return 1; }

// The three-turn check count begins anew each time the mount lands and takes
// off.
inline bool wfaCheckRestartsOnLanding()
    { return true; }

// While the unusual conditions persist the DM may call for a check as often
// as once per round.
inline bool wfaBadConditionsMayCheckPerRound()
    { return true; }

// ---- the airborne riding proficiency ----

// A nonproficient character attempting any of the special airborne feats
// automatically fails and suffers the appropriate consequences.
inline bool wfaNonproficientAutoFails()
    { return true; }

// Choosing proficiency in airborne riding requires specifying the category of
// mount to which the skill pertains.
inline bool wfaProficiencyPerCategory()
    { return true; }

// A character cannot be proficient in riding both a dragon and a griffon
// without using two proficiency slots.
inline bool wfaTwoCategoriesTwoSlots()
    { return true; }

// The -50% proficiency modifier effectively negates the +50% for riding
// without holding on, so a proficient character rides safely with both hands
// free under normal conditions.
inline bool wfaProfNegatesFreeHands()
    { return true; }

// The proficiency imparts no special ability to control or cajole an
// unwilling or uncooperative mount.
inline bool wfaProfImpartsNoControl()
    { return true; }

// The special feats are performable under ideal (not perilous) conditions
// only - the ability is safety from falling plus the feats.
inline bool wfaFeatsIdealConditionsOnly()
    { return true; }

}   // namespace rules
