-- wfa: promoted from tools/spec_r461.json (the The WSG AIRBORNE FALL CHANCE AND RIDING PROFICIENCY pins, R461: the Chapter 5 closer - the to-fall-or-not-to-fall system (the 0% base on smooth level flight at the full normal rate; the reduction ladder: the full-body strap, the lower-body strap, the proficiency, the saddle, the stirrups, the per-point ability rule over the 12 threshold with the 18 strength cap; the increase ladder: the free hands, the overload, the faster-than-normal flight, the unwilling mount, the inclement weather, the not-level flight, the below-12 per-point rule, the wind ladder over the 30-mph threshold; the every-three-turns check with the landing restart and the once-per-round exception) and the airborne riding proficiency (the per-category slots, the hands-free negation, the no-control rule, the ideal-conditions feats, the nonproficient auto-fail).);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 461,
  "prefix" = "wfa",
  "banner" = {
      "title" = "The WSG AIRBORNE FALL CHANCE AND RIDING PROFICIENCY pins, R461: the Chapter 5 closer - the to-fall-or-not-to-fall system (the 0% base on smooth level flight at the full normal rate; the reduction ladder: the full-body strap, the lower-body strap, the proficiency, the saddle, the stirrups, the per-point ability rule over the 12 threshold with the 18 strength cap; the increase ladder: the free hands, the overload, the faster-than-normal flight, the unwilling mount, the inclement weather, the not-level flight, the below-12 per-point rule, the wind ladder over the 30-mph threshold; the every-three-turns check with the landing restart and the once-per-round exception) and the airborne riding proficiency (the per-category slots, the hands-free negation, the no-control rule, the ideal-conditions feats, the nonproficient auto-fail).",
      "provenance" = "The read: the OCR session 8d6a65a0, pdf pages 49-50 = printed 48-49, cross-checked against the second OCR copy - the two read word-for-word identical. The sign convention is pinned by the p. 49 text: the proficiency enjoys a -50% modifier that effectively negates the +50% for riding without holding on, so the first six table rows are reductions and the last seven are increases over the 0% base.",
    },
  "consts" = { {
      "name" = "wfaBaseFallChancePct",
      "value" = 0,
      "comment" = "The base chance of falling: 0 percent - the mount giving a smooth and level flight at its full normal movement rate.",
    }, {
      "name" = "wfaStrapFullBodyPct",
      "value" = -200,
      "comment" = "Reduction: the rider's entire body (upper and lower) securely strapped onto the mount.",
    }, {
      "name" = "wfaStrapLowerBodyPct",
      "value" = -150,
      "comment" = "Reduction: the rider's lower body only securely strapped onto the mount.",
    }, {
      "name" = "wfaAirborneProfPct",
      "value" = -50,
      "comment" = "Reduction: the rider has proficiency in airborne riding in the appropriate category.",
    }, {
      "name" = "wfaSaddlePct",
      "value" = -10,
      "comment" = "Reduction: the rider is using a saddle.",
    }, {
      "name" = "wfaStirrupsPct",
      "value" = -10,
      "comment" = "Reduction: the saddle is equipped with stirrups.",
    }, {
      "name" = "wfaPerAbilityAbove12Pct",
      "value" = -2,
      "comment" = "Reduction per point of rider's dexterity above 12 and rider's strength above 12.",
    }, {
      "name" = "wfaAbilityModThreshold",
      "value" = 12,
      "comment" = "The ability-score threshold the per-point fall modifiers key on.",
    }, {
      "name" = "wfaStrengthCap",
      "value" = 18,
      "comment" = "Strength reads as 18 at most for the per-point fall modifier.",
    }, {
      "name" = "wfaPerAbilityBelow12Pct",
      "value" = 2,
      "comment" = "Increase per point of rider's dexterity below 12 and rider's strength below 12.",
    }, {
      "name" = "wfaFreeHandsPct",
      "value" = 50,
      "comment" = "Increase: the rider is not strapped onto the mount and not holding on - hands free or carrying something.",
    }, {
      "name" = "wfaOverloadPct",
      "value" = 20,
      "comment" = "Increase: the mount is carrying more than its normal load limit.",
    }, {
      "name" = "wfaFasterThanNormalPct",
      "value" = 20,
      "comment" = "Increase: the mount is moving faster than its full normal movement rate - diving, dodging, performing combat maneuvers.",
    }, {
      "name" = "wfaUnwillingMountPct",
      "value" = 20,
      "comment" = "Increase: the mount's demeanor is unwilling or rebellious and the creature is not charmed, subdued or similarly influenced.",
    }, {
      "name" = "wfaInclementWeatherPct",
      "value" = 20,
      "comment" = "Increase: inclement weather - sandstorm, heavy precipitation, or worse.",
    }, {
      "name" = "wfaNotFlyingLevelPct",
      "value" = 10,
      "comment" = "Increase: the mount is not flying level - sharp turns, loops, and the like.",
    }, {
      "name" = "wfaWindThresholdMph",
      "value" = 30,
      "comment" = "The wind-velocity threshold the per-mph fall modifier keys on.",
    }, {
      "name" = "wfaPerWindMphAbove30Pct",
      "value" = 1,
      "comment" = "Increase per mph of wind velocity greater than the threshold.",
    }, {
      "name" = "wfaFallCheckEveryTurns",
      "value" = 3,
      "comment" = "The fall chance is checked at least once every three turns while airborne - assuming smooth and normal flight.",
    }, {
      "name" = "wfaBadConditionsPerRounds",
      "value" = 1,
      "comment" = "Under bad weather, an uncooperative mount or abrupt changes of direction and speed, a check may be called for as often as once per round.",
    } },
  "bools" = { {
      "name" = "wfaChanceUnlessFastened",
      "value" = true,
      "comment" = "A character always has a chance of falling from the back of an airborne mount unless he is securely fastened to the creature.",
    }, {
      "name" = "wfaSaddleNoAttachmentWorse",
      "value" = true,
      "comment" = "Sitting in a saddle (or some other kind of seat) without being actually attached to the creature increases the chance.",
    }, {
      "name" = "wfaNoSaddleWorseStill",
      "value" = true,
      "comment" = "Riding without a saddle or some means of retaining the hold on the mount increases the chance further.",
    }, {
      "name" = "wfaCheckRestartsOnLanding",
      "value" = true,
      "comment" = "The three-turn check count begins anew each time the mount lands and takes off.",
    }, {
      "name" = "wfaBadConditionsMayCheckPerRound",
      "value" = true,
      "comment" = "While the unusual conditions persist the DM may call for a check as often as once per round.",
    }, {
      "name" = "wfaNonproficientAutoFails",
      "value" = true,
      "comment" = "A nonproficient character attempting any of the special airborne feats automatically fails and suffers the appropriate consequences.",
    }, {
      "name" = "wfaProficiencyPerCategory",
      "value" = true,
      "comment" = "Choosing proficiency in airborne riding requires specifying the category of mount to which the skill pertains.",
    }, {
      "name" = "wfaTwoCategoriesTwoSlots",
      "value" = true,
      "comment" = "A character cannot be proficient in riding both a dragon and a griffon without using two proficiency slots.",
    }, {
      "name" = "wfaProfNegatesFreeHands",
      "value" = true,
      "comment" = "The -50% proficiency modifier effectively negates the +50% for riding without holding on, so a proficient character rides safely with both hands free under normal conditions.",
    }, {
      "name" = "wfaProfImpartsNoControl",
      "value" = true,
      "comment" = "The proficiency imparts no special ability to control or cajole an unwilling or uncooperative mount.",
    }, {
      "name" = "wfaFeatsIdealConditionsOnly",
      "value" = true,
      "comment" = "The special feats are performable under ideal (not perilous) conditions only - the ability is safety from falling plus the feats.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['wfaAirborneProfPct']() + m['wfaFreeHandsPct']() != 0",
      "note" = "the book example: the proficiency -50% negates the +50% hands-free under normal conditions",
    }, {
      "expr" = "m['wfaStrapFullBodyPct']() >= m['wfaStrapLowerBodyPct']()",
      "note" = "the full-body strap is strictly more protective than the lower-body-only strap",
    }, {
      "expr" = "m['wfaSaddlePct']() + m['wfaStirrupsPct']() != -20",
      "note" = "the saddle and stirrups reductions sum to -20",
    }, {
      "expr" = "4 * m['wfaPerAbilityAbove12Pct']() + 4 * m['wfaPerAbilityBelow12Pct']() != 0",
      "note" = "the symmetric per-point ladder: four points above 12 (-8%) mirrors four below (+8%)",
    }, {
      "expr" = "40 - m['wfaWindThresholdMph']() != 10 * m['wfaPerWindMphAbove30Pct']()",
      "note" = "a 40-mph wind: 10 mph over the threshold at +1% per mph gives +10%",
    } },
  "audit" = {
      "label" = "R461 WSG airborne fall chance pin audit",
      "comment" = "The Chapter 5 closer: the fall-chance system (printed p. 48) and the airborne riding proficiency (printed p. 49) pin as rules/wsgfallair.h (NEW, prefix wfa): the 0% base with the seven reduction modifiers (the full-body strap -200, the lower-body strap -150, the proficiency -50, the saddle -10, the stirrups -10, the -2 per ability point above 12 with the strength cap 18) and the seven increase modifiers (the hands-free +50, the overload +20, the faster-than-normal +20, the unwilling mount +20, the inclement weather +20, the not-level +10, the +2 per ability point below 12 and the +1 per wind mph above the 30-mph threshold), the every-three-turns check cadence restarting on each landing with the bad-conditions once-per-round exception, and the proficiency pins (the per-category slots with the dragon-and-griffon two-slot example, the -50/+50 hands-free negation, no mount control, the feats under ideal conditions only, the nonproficient automatic feat failure).",
    },
}
