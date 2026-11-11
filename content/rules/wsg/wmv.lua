-- wmv: promoted from tools/spec_r501.json (the The WSG MOVEMENT/FALL-CHAIN FOLD, R501: the third seam round after gap closure. The climbing ratings (rules/wsg/wsgclimb.h), the Table 17 fall ladder (rules/wsg/wsgfall.h), the tumble rates (rules/wsg/wsgtumble.h), the stop windows (rules/wsg/wsgstop.h), the jump floors (rules/wsg/wsgjump.h), the slippery-surface cadence (rules/wsg/wsgslip.h) and the airborne fall chance (rules/wsg/wsgfallair.h) reconciled as one system: one falling character, one chain, every rate and threshold cross-checked between its headers.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 501,
  "prefix" = "wmv",
  "banner" = {
      "title" = "The WSG MOVEMENT/FALL-CHAIN FOLD, R501: the third seam round after gap closure. The climbing ratings (rules/wsg/wsgclimb.h), the Table 17 fall ladder (rules/wsg/wsgfall.h), the tumble rates (rules/wsg/wsgtumble.h), the stop windows (rules/wsg/wsgstop.h), the jump floors (rules/wsg/wsgjump.h), the slippery-surface cadence (rules/wsg/wsgslip.h) and the airborne fall chance (rules/wsg/wsgfallair.h) reconciled as one system: one falling character, one chain, every rate and threshold cross-checked between its headers.",
      "provenance" = "No new book pages: every value is the landed original re-read from its header (wdfFallDice, wdfFreeFallRate, wdtAbrasionPerFt, wdtGentleRateMin, wsfAttemptCliffSevereFt, wcsNonThiefRating, wcsFallBase, wjpStandFloorFt, wslRunCheckSegs, wfaStrapFullBodyPct and kin) and re-pinned on the fold side so the boundary identities compile and ride the mutant battery. The findings: the triangular dice ladder with the cap breaking the sequence at the top; the prose-vs-table tension (the linear formula understates every band past the first); the stop windows pinned to the damage-band top and the tumble-rate minimum; the contiguous rate ladder; and the slip-to-tumble seam between the harmless horizontal fall and the killing inclined tumble.",
      "sentinel" = "THE SETTLE: census 425 -> 426; the gap report stays 186 closed / 0 open (closed - no flips this round); the falling chain has no gaps.",
    },
  "consts" = { {
      "comment" = "the Table 17 fall-distance band count: 10, 11-20, 21-30, 31-40, 41-50 and 51-or-more feet (wdfFallBandCount).",
      "name" = "wmvFallBandCount",
      "value" = 6,
    }, {
      "comment" = "the first damage band opens at 10 feet (wdfFallMinFt(0)).",
      "name" = "wmvFallFirstBandFt",
      "value" = 10,
    }, {
      "comment" = "the open-ended 20d6 band opens at 51 feet (wdfFallMinFt(5)).",
      "name" = "wmvFallOpenBandFt",
      "value" = 51,
    }, {
      "comment" = "the 10-foot band: 1d6 (wdfFallDice(0)).",
      "name" = "wmvFallDiceB0",
      "value" = 1,
    }, {
      "comment" = "the 11-20 foot band: 3d6 (wdfFallDice(1)).",
      "name" = "wmvFallDiceB1",
      "value" = 3,
    }, {
      "comment" = "the 21-30 foot band: 6d6 (wdfFallDice(2)).",
      "name" = "wmvFallDiceB2",
      "value" = 6,
    }, {
      "comment" = "the 31-40 foot band: 10d6 (wdfFallDice(3)).",
      "name" = "wmvFallDiceB3",
      "value" = 10,
    }, {
      "comment" = "the 41-50 foot band: 15d6 (wdfFallDice(4)).",
      "name" = "wmvFallDiceB4",
      "value" = 15,
    }, {
      "comment" = "the 51-or-more band: 20d6, the maximum (wdfFallDice(5)).",
      "name" = "wmvFallDiceB5",
      "value" = 20,
    }, {
      "comment" = "the printed damage cap: 20d6 (wdfMaxFallDice).",
      "name" = "wmvMaxFallDice",
      "value" = 20,
    }, {
      "comment" = "an unimpeded free fall covers 1000 feet per round (wdfFreeFallRate).",
      "name" = "wmvFreeFallRate",
      "value" = 1000,
    }, {
      "comment" = "a fall down a severe slope covers at least 600 feet per round (wdfSevereRateMin).",
      "name" = "wmvSevereRateMin",
      "value" = 600,
    }, {
      "comment" = "a fall down a severe slope covers at most 800 feet per round (wdfSevereRateMax).",
      "name" = "wmvSevereRateMax",
      "value" = 800,
    }, {
      "comment" = "tumble abrasion damage is rolled for every 10 feet beyond the free distance (wdtAbrasionPerFt).",
      "name" = "wmvAbrasionPerFt",
      "value" = 10,
    }, {
      "comment" = "an unimpeded gentle-slope tumble covers at least 100 feet per round (wdtGentleRateMin).",
      "name" = "wmvGentleTumbleMin",
      "value" = 100,
    }, {
      "comment" = "a gentle-slope tumble covers at most 300 feet in one round (wdtGentleRateMax).",
      "name" = "wmvGentleTumbleMax",
      "value" = 300,
    }, {
      "comment" = "a moderate-slope tumble covers at least 300 feet per round (wdtModerateRateMin).",
      "name" = "wmvModerateTumbleMin",
      "value" = 300,
    }, {
      "comment" = "a moderate-slope tumble covers at most 500 feet per round (wdtModerateRateMax).",
      "name" = "wmvModerateTumbleMax",
      "value" = 500,
    }, {
      "comment" = "the stop attempt must come within the first 50 feet of a cliff or severe-slope fall (wsfAttemptCliffSevereFt).",
      "name" = "wmvStopCliffSevereFt",
      "value" = 50,
    }, {
      "comment" = "the stop window on a moderate slope: within 75 feet (wsfAttemptModerateFt).",
      "name" = "wmvStopModerateFt",
      "value" = 75,
    }, {
      "comment" = "the stop window on a gentle slope: within 100 feet (wsfAttemptGentleFt).",
      "name" = "wmvStopGentleFt",
      "value" = 100,
    }, {
      "comment" = "the non-thief without mountaineering has a Climbing Rating of 40 percent (wcsNonThiefRating).",
      "name" = "wmvNonThiefRating",
      "value" = 40,
    }, {
      "comment" = "the mountaineer with tools on a restricted surface: 80 percent (wcsMountaineerRating).",
      "name" = "wmvMountaineerRating",
      "value" = 80,
    }, {
      "comment" = "the climbing fall chance is 100 minus the Climbing Rating (wcsFallBase).",
      "name" = "wmvFallBase",
      "value" = 100,
    }, {
      "comment" = "a running broad jump requires a 20-foot straight-line run (wjpRunRequiredFt).",
      "name" = "wmvRunRequiredFt",
      "value" = 20,
    }, {
      "comment" = "the running broad jump advantage: 4 feet over standing (wjpRunningAdvantageFt).",
      "name" = "wmvRunningAdvantageFt",
      "value" = 4,
    }, {
      "comment" = "a failed thin-barrier landing is a 1d3 heap (wjpHeapDmgDie).",
      "name" = "wmvHeapDmgDie",
      "value" = 3,
    }, {
      "comment" = "the heap damage is possible for a jump of five feet or higher (wjpHeapMinFt).",
      "name" = "wmvHeapMinFt",
      "value" = 5,
    }, {
      "comment" = "no broad jump reduces below 2 feet (wjpStandFloorFt).",
      "name" = "wmvStandFloorFt",
      "value" = 2,
    }, {
      "comment" = "no high jump reduces below 1 foot (wjpHighFloorFt).",
      "name" = "wmvHighFloorFt",
      "value" = 1,
    }, {
      "comment" = "a high jump covers half its height horizontally (wjpHighHorizDiv).",
      "name" = "wmvHighHorizDiv",
      "value" = 2,
    }, {
      "comment" = "running on a slippery surface demands a Dex Check every five segments (wslRunCheckSegs).",
      "name" = "wmvSlipRunCheckSegs",
      "value" = 5,
    }, {
      "comment" = "moving at half rate allows turning without a check (wslCautiousRateDiv).",
      "name" = "wmvCautiousRateDiv",
      "value" = 2,
    }, {
      "comment" = "the base airborne fall chance on a smooth level flight: 0 percent (wfaBaseFallChancePct).",
      "name" = "wmvAirBaseFallPct",
      "value" = 0,
    }, {
      "comment" = "the full-body strap reduction: -200 percent (wfaStrapFullBodyPct).",
      "name" = "wmvStrapFullBodyPct",
      "value" = -200,
    }, {
      "comment" = "the lower-body-only strap reduction: -150 percent (wfaStrapLowerBodyPct).",
      "name" = "wmvStrapLowerBodyPct",
      "value" = -150,
    }, {
      "comment" = "the airborne-riding proficiency reduction: -50 percent (wfaAirborneProfPct).",
      "name" = "wmvAirborneProfPct",
      "value" = -50,
    }, {
      "comment" = "the saddle reduction: -10 percent (wfaSaddlePct).",
      "name" = "wmvSaddlePct",
      "value" = -10,
    }, {
      "comment" = "the stirrups reduction: -10 percent (wfaStirrupsPct).",
      "name" = "wmvStirrupsPct",
      "value" = -10,
    } },
  "bools" = { {
      "comment" = "the Table 17 dice are the triangular numbers 1, 3, 6, 10, 15 - each band adds one more die than the previous band added: increments 2, 3, 4, 5.",
      "name" = "wmvDiceLadderTriangular",
      "value" = true,
    }, {
      "comment" = "the 51-or-more band caps at 20d6 - one die SHORT of the pure triangular sequence value 21; the printed maximum breaks the ladder it completes.",
      "name" = "wmvCapBreaksSequence",
      "value" = true,
    }, {
      "comment" = "the prose says 1d6 cumulative per 10 feet, but the printed table is steeper than linear at every band past the first - a 20-foot fall is 3d6, not 2d6; the table is the authority.",
      "name" = "wmvProseVsTableTension",
      "value" = true,
    }, {
      "comment" = "the cliff/severe stop window of 50 feet is exactly the top of the 41-50 damage band - one foot into the open-ended 20d6 band and it is too late to stop.",
      "name" = "wmvStopWindowBandTop",
      "value" = true,
    }, {
      "comment" = "the gentle stop window of 100 feet equals the gentle tumble rate minimum of 100 feet per round - the attempt must come within the first round of the slowest tumble.",
      "name" = "wmvGentleWindowEqualsRate",
      "value" = true,
    }, {
      "comment" = "the rate ladder is contiguous and strictly ascending: gentle tumble tops at 300 where moderate begins, moderate tops at 500 below the severe 600, severe tops at 800 below the 1000 free fall.",
      "name" = "wmvRateLadderContiguous",
      "value" = true,
    }, {
      "comment" = "the fall damage and the tumble abrasion share the same 10-foot granularity - one die per 10 feet beyond the threshold.",
      "name" = "wmvTenFootGranularity",
      "value" = true,
    }, {
      "comment" = "the horizontal slip deals no direct damage (wslFallNoDirectDamage) while the inclined tumble abrasion kills - the seam between the flat and the slope is the whole difference.",
      "name" = "wmvSlipHarmlessTumbleDeadly",
      "value" = true,
    }, {
      "comment" = "the climbing fall chance is the complement of the rating: 100 minus 40 leaves the non-thief a 60 percent fall chance.",
      "name" = "wmvClimbFallIsComplement",
      "value" = true,
    }, {
      "comment" = "the airborne reductions are ordered by security: the full-body strap halves the lower-body strap, the saddle and stirrups each add 10, and the base chance is zero.",
      "name" = "wmvAirLadderOrdered",
      "value" = true,
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['wmvFallBandCount']() != 6 or m['wmvFallDiceB0']() != 1 or m['wmvFallDiceB1']() != 3 or m['wmvFallDiceB2']() != 6 or m['wmvFallDiceB3']() != 10 or m['wmvFallDiceB4']() != 15 or m['wmvFallDiceB5']() != 20",
      "note" = "the Table 17 dice ladder",
    }, {
      "expr" = "m['wmvFallDiceB1']() - m['wmvFallDiceB0']() != 2 or m['wmvFallDiceB2']() - m['wmvFallDiceB1']() != 3 or m['wmvFallDiceB3']() - m['wmvFallDiceB2']() != 4 or m['wmvFallDiceB4']() - m['wmvFallDiceB3']() != 5",
      "note" = "the ladder is triangular: each band adds one more die than the previous band added",
    }, {
      "expr" = "m['wmvFallDiceB5']() - m['wmvFallDiceB4']() != 5 or m['wmvFallDiceB5']() == m['wmvFallDiceB4']() + 6 or m['wmvMaxFallDice']() != m['wmvFallDiceB5']()",
      "note" = "the cap breaks the sequence: the last increment repeats instead of stepping to six - 20, not 21",
    }, {
      "expr" = "m['wmvFallOpenBandFt']() - m['wmvStopCliffSevereFt']() != 1",
      "note" = "the open band opens one foot past the stop window",
    }, {
      "expr" = "m['wmvStopGentleFt']() != m['wmvGentleTumbleMin']()",
      "note" = "the gentle stop window equals the gentle tumble rate minimum",
    }, {
      "expr" = "m['wmvGentleTumbleMax']() != m['wmvModerateTumbleMin']() or m['wmvModerateTumbleMax']() >= m['wmvSevereRateMin']() or m['wmvSevereRateMax']() >= m['wmvFreeFallRate']()",
      "note" = "the rate ladder is contiguous and strictly ascending",
    }, {
      "expr" = "m['wmvFallBase']() - m['wmvNonThiefRating']() != 60 or m['wmvFallBase']() - m['wmvMountaineerRating']() != 20",
      "note" = "the climb fall chance is the complement of the rating",
    }, {
      "expr" = "m['wmvStandFloorFt']() != 2 or m['wmvHighFloorFt']() != 1 or m['wmvHeapMinFt']() != 5 or m['wmvHeapDmgDie']() != 3 or m['wmvRunRequiredFt']() != 20",
      "note" = "the jump floors and the heap",
    }, {
      "expr" = "m['wmvSlipRunCheckSegs']() != 5 or m['wmvCautiousRateDiv']() != 2",
      "note" = "the slip cadence and the cautious divisor",
    }, {
      "expr" = "m['wmvStrapFullBodyPct']() + 200 != 0 or m['wmvStrapLowerBodyPct']() + 150 != 0 or m['wmvAirborneProfPct']() + 50 != 0 or m['wmvSaddlePct']() != m['wmvStirrupsPct']() or m['wmvAirBaseFallPct']() != 0 or m['wmvStrapFullBodyPct']() >= m['wmvStrapLowerBodyPct']()",
      "note" = "the airborne reduction ladder is ordered",
    }, {
      "expr" = "m['wmvAbrasionPerFt']() != 10 or m['wmvFallFirstBandFt']() != 10",
      "note" = "the ten-foot granularity shared by the fall and the tumble",
    }, {
      "expr" = "m['wmvStopModerateFt']() - m['wmvStopCliffSevereFt']() != 25 or m['wmvStopGentleFt']() - m['wmvStopModerateFt']() != 25",
      "note" = "the moderate stop window sits between its neighbors",
    } },
  "audit" = {
      "label" = "R501 WSG movement fall fold audit",
      "comment" = "The WSG movement/fall-chain fold, the third seam round after gap closure: no new book pages, the R499 pattern applied to the climbing-and-falling chapter. One falling character flows through seven landed headers: the climbing ratings (rules/wsg/wsgclimb.h R435: the 40 percent non-thief, the 80 percent mountaineer, the fall chance as 100 minus the rating), the Table 17 fall ladder (rules/wsg/wsgfall.h R437: the six bands 1, 3, 6, 10, 15, 20 dice, the 1000-foot free-fall rate, the 600-800 severe slope), the tumble rates (rules/wsg/wsgtumble.h R438: the 10-foot abrasion granularity, the 100-300 gentle and 300-500 moderate rates), the stop windows (rules/wsg/wsgstop.h R439: 50 feet cliff or severe, 75 moderate, 100 gentle), the jump floors (rules/wsg/wsgjump.h R448: the 2-foot broad and 1-foot high floors, the 20-foot run, the 1d3 heap at 5 feet), the slippery-surface cadence (rules/wsg/wsgslip.h R447: the five-segment run check, the half-rate caution) and the airborne fall chance (rules/wsg/wsgfallair.h R461: the zero base, the -200/-150 straps, the -50 proficiency, the -10 saddle and stirrups). The findings: the Table 17 dice are the triangular numbers (increments 2, 3, 4, 5) and the 51-or-more band caps at 20d6 ONE DIE SHORT of the pure sequence value 21; the prose linear 1d6-per-10-feet understates the printed table (3d6 at 20 feet, not 2d6); the cliff/severe stop window of 50 feet is exactly the top of the 41-50 damage band; the gentle stop window equals the gentle tumble rate minimum; the rate ladder is contiguous (100-300, 300-500, 600-800, 1000); and the horizontal slip deals no direct damage while the inclined tumble abrasion kills.",
    },
}
