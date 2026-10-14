// =========================================================================================
// Adnd1 - rules/wsgbreath.h
// The WSG HOLDING ONE'S BREATH, R454: first the surfacing rules that open the
// page - the base surfacing rate, like the diving rate, is 2 inches (doubled
// for a character who is NOT encumbered, reduced for moderate or heavy
// encumbrance), and to travel upward at that rate the swimmer must be
// ACTIVELY working to get himself to the surface; otherwise the natural
// buoyancy of his body brings him to the surface at ONE-HALF inch, or 5 feet
// per round (modified for encumbrance), if he is inert - and it is possible
// to purposely encumber oneself with easily-dropped items to dive deep and
// return quickly after divesting the weight. The diving bonuses for leaping
// into the water are NOT cumulative with the depth increases for encumbered
// characters; the extra depth is added AFTER encumbrance is taken into
// account - the printed example: a moderately encumbered character diving
// from 15 feet travels 6 inches down, 4 for the doubled normal rate plus 2
// for the leap. The breath formula: the base time a character can hold his
// breath underwater is a number of rounds equal to ONE-THIRD of his
// constitution score (ROUNDED UP), assuming a deep breath before submerging
// and no strenuous activity; normal movement is allowed, as are opening a
// locked chest, searching for a secret passage, or casting a spell. Without a
// chance to fill his lungs, the time is CUT IN HALF (rounded up); strenuous
// activity such as combat also cuts it in half; the penalties are CUMULATIVE,
// so an abruptly dumped character forced to fight holds his breath only
// ONE-FOURTH as long - but any character can hold his breath for AT LEAST ONE
// ROUND regardless of the penalties. When the time expires he does not
// automatically die: he stays alive as long as he makes a successful
// Constitution Check once per round, each check after the first with a
// CUMULATIVE +2 modifier - the printed example: a constitution of 12 holds
// breath for 4 rounds, the first check at the end of the 5th round
// unmodified, +2 at the end of the 6th, +4 at the 7th. A character who has
// not run out of air can surface by swimming (if proficient) or by staying
// still and letting buoyancy carry him up - the ONLY way a non-swimmer can
// surface - and can divest extra weight; a character out of air is
// UNCONSCIOUS, cannot move, and must be pulled to the surface before he fails
// a Constitution Check. Not underwater: the same formula, but ONE ROUND IS
// ADDED to the time limit, and the unprepared/strenuous penalties are applied
// AFTER that round is added, not before. And a character cannot escape a
// poisonous gas or noxious substance (such as the odor of a troglodyte)
// unless he holds his breath BEFORE he is affected - a small amount of gas is
// just as harmful as an extended dose. Census 378 -> 379.
// census 378 -> 379.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 43; the
// user own copy OCR (page 44) cross-checked against the archive djvu word
// layer (Guide_0043) - the section reads CLEAN two-way, every number (the
// 2-inch surfacing rate, the half-inch/5-foot inert buoyancy, the 6-inch
// non-cumulative example, the one-third constitution formula, the halved
// penalties and their one-fourth combination, the one-round floor, the
// cumulative +2 checks, the con-12/4-round example with the 5th/6th/7th-round
// check cadence, the one-round not-underwater addition and the gas rules)
// matched exactly; the djvu garbles only the one-third fraction glyph itself,
// corroborated by the printed con-12 -> 4-round example arithmetic - no
// eye-reads needed.
//
// Surface at 2 inches if you work for it - drift up at half an inch, 5 feet,
// if you do not - and never let the leap bonus ride the encumbrance increase.
// A third of your constitution in rounds of air, rounded up; no deep breath
// or a fight halves it, both quarter it, one round is yours regardless. Past
// the limit, roll Constitution every round at +2 a check, until the air runs
// out of you and someone must pull you up. Ashore, one round more - and hold
// your breath before the gas, not after.
//
namespace rules {

// ---- the surfacing rate and buoyancy ----

// The base surfacing rate, like the diving rate, is 2 inches, doubled for a
// character who is not encumbered and reduced for a character who is
// moderately or heavily encumbered.
inline int whbBaseSurfRateIn()
    { return 2; }

// To be able to travel upward at the surfacing rate, the swimmer must be
// actively working to get himself to the surface.
inline bool whbSurfaceRateNeedsWork()
    { return true; }

// Otherwise the natural buoyancy of a character's body will bring him to the
// surface at one-half inch (5 feet per round), modified for encumbrance, if
// he is inert.
inline bool whbInertBuoyancyRise()
    { return true; }

// The natural buoyancy of a character's body will bring him to the surface at
// one-half inch per round if he is inert.
inline int whbInertRiseNum()
    { return 1; }

// The inert rise rate is one-half inch per round, modified for encumbrance.
inline int whbInertRiseDen()
    { return 2; }

// The inert buoyancy rate is 5 feet per round.
inline int whbInertRiseFt()
    { return 5; }

// It is possible for a character to purposely encumber himself with items
// that can be easily gotten rid of, so that he can make a deep dive and then
// return quickly to the surface after divesting himself of the extra weight.
inline bool whbDeliberateEncumbranceTrick()
    { return true; }

// The diving bonuses for leaping into the water are not cumulative with the
// depth increases for moderately, heavily and severely encumbered characters;
// the extra depth is added to the dive after encumbrance is taken into
// account.
inline bool whbLeapBonusNotCumulative()
    { return true; }

// ---- the breath formula and penalties ----

// The base amount of time a character can hold his breath underwater is a
// number of rounds equal to one-third of his constitution score, rounded up.
inline int whbBreathConDiv()
    { return 3; }

// The base breath formula assumes the character has a chance to take a deep
// breath before submerging and does not perform any strenuous physical
// activity while underwater.
inline bool whbDeepBreathAssumed()
    { return true; }

// Normal movement (underwater swimming, diving or surfacing) is allowed while
// holding breath, as are activities such as opening a locked chest, searching
// for a secret passage, or casting a spell if being underwater does not
// prohibit the casting.
inline bool whbNormalMovementAllowed()
    { return true; }

// If the character did not have a chance to fill his lungs with air before
// going under, the time he can hold his breath is cut in half, rounded up.
inline bool whbUnpreparedHalved()
    { return true; }

// If the character did not have a chance to fill his lungs before going
// under, the time is cut in half (rounded up); strenuous activity such as
// combat also cuts it in half.
inline int whbPenaltyDiv()
    { return 2; }

// If the character engages in strenuous activity such as combat, the time is
// also cut in half.
inline bool whbStrenuousHalved()
    { return true; }

// The unprepared and strenuous penalties are cumulative with each other -
// both together leave only one-fourth of the base time.
inline bool whbPenaltiesCumulative()
    { return true; }

// The penalties are cumulative with each other: a character abruptly dumped
// into the water and then forced to fight holds his breath only one-fourth as
// long.
inline int whbBothPenaltyDiv()
    { return 4; }

// Any character is able to hold his breath for at least one round, regardless
// of the effect of these penalties.
inline bool whbAtLeastOneRound()
    { return true; }

// Any character is able to hold his breath for at least one round, regardless
// of the effect of these penalties.
inline int whbMinBreathRounds()
    { return 1; }

// ---- the expiration checks ----

// When the time limit expires, the character does not automatically expire:
// he can stay alive as long as he makes a successful Constitution Check once
// per round.
inline bool whbConCheckOncePerRound()
    { return true; }

// Each Constitution Check after the first one is made with a cumulative +2
// modifier to the die roll.
inline bool whbChecksCumulativePlusTwo()
    { return true; }

// Each Constitution Check after the first is made with a cumulative +2
// modifier to the die roll.
inline int whbConCheckStep()
    { return 2; }

// The printed example: a character with a constitution of 12 can hold his
// breath underwater for 4 rounds under the most favorable circumstances.
inline int whbExampleCon()
    { return 12; }

// The example limit: 4 rounds for the constitution-12 character - one-third
// of 12.
inline int whbExampleRounds()
    { return 4; }

// After 4 rounds the example character has run out of air but can still
// survive: the first Constitution Check comes at the end of the 5th round, +2
// at the end of the 6th, +4 at the 7th.
inline int whbExampleFirstCheckRound()
    { return 5; }

// A character who has not run out of air can get to the surface by swimming
// (if he has proficiency) or by remaining still and allowing his body's
// natural buoyancy to carry him upward - the only way a non-swimmer can
// surface.
inline bool whbNonswimmerBuoyancyOnly()
    { return true; }

// When a character runs out of air, he is unconscious and cannot move under
// his own power; to survive, he must be pulled or otherwise moved up to the
// surface before he fails a Constitution Check.
inline bool whbOutOfAirUnconscious()
    { return true; }

// ---- the not-underwater variant and gases ----

// If a character wants to hold his breath when not underwater, the formula is
// used but one round is added to the time limit.
inline bool whbNotUwOneRoundAdded()
    { return true; }

// If a character wants to hold his breath when not underwater, the formula is
// used but one round is added to the time limit.
inline int whbNotUwBonusRounds()
    { return 1; }

// The penalties for being unprepared and for engaging in strenuous activity
// are applied after the one round of time is added, not before.
inline bool whbNotUwPenaltiesAfterBonus()
    { return true; }

// A character cannot escape the effects of a poisonous gas or some other
// noxious substance (such as the odor of a troglodyte) unless he holds his
// breath before he is affected.
inline bool whbGasHoldBeforeAffected()
    { return true; }

// A small amount of poisonous gas is just as harmful as an extended dose -
// holding one's breath after ingesting some of the vapors does no good.
inline bool whbSmallDoseFullHarm()
    { return true; }

}   // namespace rules
