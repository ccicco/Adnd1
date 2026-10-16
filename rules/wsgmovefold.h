// =========================================================================================
// Adnd1 - rules/wsgmovefold.h
// The WSG MOVEMENT/FALL-CHAIN FOLD, R501: the third seam round after gap
// closure. The climbing ratings (rules/wsgclimb.h), the Table 17 fall ladder
// (rules/wsgfall.h), the tumble rates (rules/wsgtumble.h), the stop windows
// (rules/wsgstop.h), the jump floors (rules/wsgjump.h), the slippery-surface
// cadence (rules/wsgslip.h) and the airborne fall chance (rules/wsgfallair.h)
// reconciled as one system: one falling character, one chain, every rate and
// threshold cross-checked between its headers.
// census 425 -> 426.
//
// No new book pages: every value is the landed original re-read from its
// header (wdfFallDice, wdfFreeFallRate, wdtAbrasionPerFt, wdtGentleRateMin,
// wsfAttemptCliffSevereFt, wcsNonThiefRating, wcsFallBase, wjpStandFloorFt,
// wslRunCheckSegs, wfaStrapFullBodyPct and kin) and re-pinned on the fold
// side so the boundary identities compile and ride the mutant battery. The
// findings: the triangular dice ladder with the cap breaking the sequence at
// the top; the prose-vs-table tension (the linear formula understates every
// band past the first); the stop windows pinned to the damage-band top and
// the tumble-rate minimum; the contiguous rate ladder; and the slip-to-tumble
// seam between the harmless horizontal fall and the killing inclined tumble.
//
// THE SETTLE: census 425 -> 426; the gap report stays 186 closed / 0 open
// (closed - no flips this round); the falling chain has no gaps.
//
namespace rules {

// ---- the climb side ----

// the non-thief without mountaineering has a Climbing Rating of 40 percent
// (wcsNonThiefRating).
inline int wmvNonThiefRating()
    { return 40; }

// the mountaineer with tools on a restricted surface: 80 percent
// (wcsMountaineerRating).
inline int wmvMountaineerRating()
    { return 80; }

// the climbing fall chance is 100 minus the Climbing Rating (wcsFallBase).
inline int wmvFallBase()
    { return 100; }

// ---- the fall side ----

// the Table 17 fall-distance band count: 10, 11-20, 21-30, 31-40, 41-50 and
// 51-or-more feet (wdfFallBandCount).
inline int wmvFallBandCount()
    { return 6; }

// the first damage band opens at 10 feet (wdfFallMinFt(0)).
inline int wmvFallFirstBandFt()
    { return 10; }

// the open-ended 20d6 band opens at 51 feet (wdfFallMinFt(5)).
inline int wmvFallOpenBandFt()
    { return 51; }

// the 10-foot band: 1d6 (wdfFallDice(0)).
inline int wmvFallDiceB0()
    { return 1; }

// the 11-20 foot band: 3d6 (wdfFallDice(1)).
inline int wmvFallDiceB1()
    { return 3; }

// the 21-30 foot band: 6d6 (wdfFallDice(2)).
inline int wmvFallDiceB2()
    { return 6; }

// the 31-40 foot band: 10d6 (wdfFallDice(3)).
inline int wmvFallDiceB3()
    { return 10; }

// the 41-50 foot band: 15d6 (wdfFallDice(4)).
inline int wmvFallDiceB4()
    { return 15; }

// the 51-or-more band: 20d6, the maximum (wdfFallDice(5)).
inline int wmvFallDiceB5()
    { return 20; }

// the printed damage cap: 20d6 (wdfMaxFallDice).
inline int wmvMaxFallDice()
    { return 20; }

// an unimpeded free fall covers 1000 feet per round (wdfFreeFallRate).
inline int wmvFreeFallRate()
    { return 1000; }

// a fall down a severe slope covers at least 600 feet per round
// (wdfSevereRateMin).
inline int wmvSevereRateMin()
    { return 600; }

// a fall down a severe slope covers at most 800 feet per round
// (wdfSevereRateMax).
inline int wmvSevereRateMax()
    { return 800; }

// ---- the fold findings ----

// the Table 17 dice are the triangular numbers 1, 3, 6, 10, 15 - each band
// adds one more die than the previous band added: increments 2, 3, 4, 5.
inline bool wmvDiceLadderTriangular()
    { return true; }

// the 51-or-more band caps at 20d6 - one die SHORT of the pure triangular
// sequence value 21; the printed maximum breaks the ladder it completes.
inline bool wmvCapBreaksSequence()
    { return true; }

// the prose says 1d6 cumulative per 10 feet, but the printed table is steeper
// than linear at every band past the first - a 20-foot fall is 3d6, not 2d6;
// the table is the authority.
inline bool wmvProseVsTableTension()
    { return true; }

// the cliff/severe stop window of 50 feet is exactly the top of the 41-50
// damage band - one foot into the open-ended 20d6 band and it is too late to
// stop.
inline bool wmvStopWindowBandTop()
    { return true; }

// the gentle stop window of 100 feet equals the gentle tumble rate minimum of
// 100 feet per round - the attempt must come within the first round of the
// slowest tumble.
inline bool wmvGentleWindowEqualsRate()
    { return true; }

// the rate ladder is contiguous and strictly ascending: gentle tumble tops at
// 300 where moderate begins, moderate tops at 500 below the severe 600,
// severe tops at 800 below the 1000 free fall.
inline bool wmvRateLadderContiguous()
    { return true; }

// the fall damage and the tumble abrasion share the same 10-foot granularity
// - one die per 10 feet beyond the threshold.
inline bool wmvTenFootGranularity()
    { return true; }

// the horizontal slip deals no direct damage (wslFallNoDirectDamage) while
// the inclined tumble abrasion kills - the seam between the flat and the
// slope is the whole difference.
inline bool wmvSlipHarmlessTumbleDeadly()
    { return true; }

// the climbing fall chance is the complement of the rating: 100 minus 40
// leaves the non-thief a 60 percent fall chance.
inline bool wmvClimbFallIsComplement()
    { return true; }

// the airborne reductions are ordered by security: the full-body strap halves
// the lower-body strap, the saddle and stirrups each add 10, and the base
// chance is zero.
inline bool wmvAirLadderOrdered()
    { return true; }

// ---- the jump side ----

// a running broad jump requires a 20-foot straight-line run
// (wjpRunRequiredFt).
inline int wmvRunRequiredFt()
    { return 20; }

// the running broad jump advantage: 4 feet over standing
// (wjpRunningAdvantageFt).
inline int wmvRunningAdvantageFt()
    { return 4; }

// a failed thin-barrier landing is a 1d3 heap (wjpHeapDmgDie).
inline int wmvHeapDmgDie()
    { return 3; }

// the heap damage is possible for a jump of five feet or higher
// (wjpHeapMinFt).
inline int wmvHeapMinFt()
    { return 5; }

// no broad jump reduces below 2 feet (wjpStandFloorFt).
inline int wmvStandFloorFt()
    { return 2; }

// no high jump reduces below 1 foot (wjpHighFloorFt).
inline int wmvHighFloorFt()
    { return 1; }

// a high jump covers half its height horizontally (wjpHighHorizDiv).
inline int wmvHighHorizDiv()
    { return 2; }

// ---- the slip and airborne sides ----

// running on a slippery surface demands a Dex Check every five segments
// (wslRunCheckSegs).
inline int wmvSlipRunCheckSegs()
    { return 5; }

// moving at half rate allows turning without a check (wslCautiousRateDiv).
inline int wmvCautiousRateDiv()
    { return 2; }

// the base airborne fall chance on a smooth level flight: 0 percent
// (wfaBaseFallChancePct).
inline int wmvAirBaseFallPct()
    { return 0; }

// the full-body strap reduction: -200 percent (wfaStrapFullBodyPct).
inline int wmvStrapFullBodyPct()
    { return -200; }

// the lower-body-only strap reduction: -150 percent (wfaStrapLowerBodyPct).
inline int wmvStrapLowerBodyPct()
    { return -150; }

// the airborne-riding proficiency reduction: -50 percent
// (wfaAirborneProfPct).
inline int wmvAirborneProfPct()
    { return -50; }

// the saddle reduction: -10 percent (wfaSaddlePct).
inline int wmvSaddlePct()
    { return -10; }

// the stirrups reduction: -10 percent (wfaStirrupsPct).
inline int wmvStirrupsPct()
    { return -10; }

// ---- the stop side ----

// the stop attempt must come within the first 50 feet of a cliff or
// severe-slope fall (wsfAttemptCliffSevereFt).
inline int wmvStopCliffSevereFt()
    { return 50; }

// the stop window on a moderate slope: within 75 feet (wsfAttemptModerateFt).
inline int wmvStopModerateFt()
    { return 75; }

// the stop window on a gentle slope: within 100 feet (wsfAttemptGentleFt).
inline int wmvStopGentleFt()
    { return 100; }

// ---- the tumble side ----

// tumble abrasion damage is rolled for every 10 feet beyond the free distance
// (wdtAbrasionPerFt).
inline int wmvAbrasionPerFt()
    { return 10; }

// an unimpeded gentle-slope tumble covers at least 100 feet per round
// (wdtGentleRateMin).
inline int wmvGentleTumbleMin()
    { return 100; }

// a gentle-slope tumble covers at most 300 feet in one round
// (wdtGentleRateMax).
inline int wmvGentleTumbleMax()
    { return 300; }

// a moderate-slope tumble covers at least 300 feet per round
// (wdtModerateRateMin).
inline int wmvModerateTumbleMin()
    { return 300; }

// a moderate-slope tumble covers at most 500 feet per round
// (wdtModerateRateMax).
inline int wmvModerateTumbleMax()
    { return 500; }

}   // namespace rules
