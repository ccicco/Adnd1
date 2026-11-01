-- wtw: promoted from tools/spec_r453.json (the The WSG TREADING WATER, R453: a character with swimming proficiency who is afloat in calm water can remain in one place, by treading water, for a number of turns equal to TWICE his endurance score - in other words, he uses up one endurance point for every two turns spent treading water. A character WITHOUT proficiency in swimming can safely tread water for a number of rounds equal to his STRENGTH score; this time limit is modified for encumbrance in the same way that a swimmer's endurance is modified. When the time limit expires, and at the expiration of every round thereafter, the character must make a Strength Check to remain afloat, and every check after the first one is made with a CUMULATIVE +1 modifier to the die roll. The printed example: a character with a strength of 6 who is not encumbered can tread water for at least 12 rounds - the strength limit doubled by the unencumbered endurance multiplier - with the unmodified check at the end of the 12th round, +1 at the end of the 13th, +2 at the end of the 14th, and so on. A character treading water in a current has no control over his movement: he is carried in the direction of the current at a rate equal to the speed of the current, modified for his encumbrance just as for swimming movement. A proficient swimmer can prevent himself from moving with the current and maintain the same position in the water - but then he is effectively SWIMMING, not treading water, and endurance is assessed accordingly. A nonproficient character cannot prevent himself from being carried along by the current; if he attempts to do so, he will begin to SINK immediately. Census 377 -> 378.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 453,
  "prefix" = "wtw",
  "banner" = {
      "title" = "The WSG TREADING WATER, R453: a character with swimming proficiency who is afloat in calm water can remain in one place, by treading water, for a number of turns equal to TWICE his endurance score - in other words, he uses up one endurance point for every two turns spent treading water. A character WITHOUT proficiency in swimming can safely tread water for a number of rounds equal to his STRENGTH score; this time limit is modified for encumbrance in the same way that a swimmer's endurance is modified. When the time limit expires, and at the expiration of every round thereafter, the character must make a Strength Check to remain afloat, and every check after the first one is made with a CUMULATIVE +1 modifier to the die roll. The printed example: a character with a strength of 6 who is not encumbered can tread water for at least 12 rounds - the strength limit doubled by the unencumbered endurance multiplier - with the unmodified check at the end of the 12th round, +1 at the end of the 13th, +2 at the end of the 14th, and so on. A character treading water in a current has no control over his movement: he is carried in the direction of the current at a rate equal to the speed of the current, modified for his encumbrance just as for swimming movement. A proficient swimmer can prevent himself from moving with the current and maintain the same position in the water - but then he is effectively SWIMMING, not treading water, and endurance is assessed accordingly. A nonproficient character cannot prevent himself from being carried along by the current; if he attempts to do so, he will begin to SINK immediately. Census 377 -> 378.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 43; the user own copy OCR (page 44) cross-checked against the archive djvu word layer (Guide_0043) - the section reads CLEAN two-way, every number (the twice-endurance turns, the one-point-per-two-turns rate, the strength-score limit, the cumulative +1 check modifier, the 6-strength/12-round example with the +1/+2 follow-on checks, and the sink-immediately rule) matched exactly; the only djvu garbles are the section header and word breaks - no eye-reads needed.",
      "sentinel" = "Tread calm water twice your endurance in turns, a point every two turns - or, without the skill, hold your head up for your strength in rounds, modified by encumbrance like endurance, then roll Strength every round at +1 a check while the current carries you off. Fight the current and swim, if you can - if you cannot, you sink.",
    },
  "consts" = { {
      "name" = "wtwProfTurnsPerEndPt",
      "value" = 2,
      "comment" = "A character with swimming proficiency who is afloat in calm water can remain in one place, by treading water, for a number of turns equal to twice his endurance score - one endurance point for every two turns spent treading water.",
    }, {
      "name" = "wtwNonprofRoundsPerStrPt",
      "value" = 1,
      "comment" = "A character without proficiency in swimming can safely tread water for a number of rounds equal to his strength score.",
    }, {
      "name" = "wtwCumCheckStep",
      "value" = 1,
      "comment" = "Every Strength Check after the first one is made with a cumulative +1 modifier to the die roll.",
    }, {
      "name" = "wtwExampleStr",
      "value" = 6,
      "comment" = "The printed example: a character with a strength of 6 who is not encumbered can tread water for at least 12 rounds.",
    }, {
      "name" = "wtwExampleRounds",
      "value" = 12,
      "comment" = "The example limit: 12 rounds for the strength-6 unencumbered character - the strength limit doubled by the unencumbered endurance modifier.",
    }, {
      "name" = "wtwExampleFirstModRound",
      "value" = 13,
      "comment" = "At the end of the 12th round the example character makes an unmodified Strength Check; at the end of the 13th round the check is made with a +1 modifier, at the end of the 14th with +2, and so on.",
    } },
  "bools" = { {
      "name" = "wtwProfCalmWaterHold",
      "value" = true,
      "comment" = "A character with swimming proficiency who is afloat in calm water can remain in one place by treading water.",
    }, {
      "name" = "wtwProfLimitTwiceEndurance",
      "value" = true,
      "comment" = "The proficient treading limit is a number of turns equal to twice the endurance score - one endurance point spent per two turns.",
    }, {
      "name" = "wtwNonprofLimitIsStrength",
      "value" = true,
      "comment" = "The nonproficient treading limit is a number of rounds equal to the strength score.",
    }, {
      "name" = "wtwNonprofLimitEncModified",
      "value" = true,
      "comment" = "The nonproficient time limit is modified for encumbrance in the same way that a swimmer's endurance is modified.",
    }, {
      "name" = "wtwStrengthCheckAtExpiry",
      "value" = true,
      "comment" = "When the time limit expires, and at the expiration of every round thereafter, the character must make a Strength Check to remain afloat.",
    }, {
      "name" = "wtwChecksCumulativePlusOne",
      "value" = true,
      "comment" = "Every check after the first one is made with a cumulative +1 modifier to the die roll.",
    }, {
      "name" = "wtwCurrentCarriesTreader",
      "value" = true,
      "comment" = "A character treading water in a current has no control over his movement; he is carried in the direction of the current at a rate equal to the speed of the current, modified for his encumbrance just as for swimming movement.",
    }, {
      "name" = "wtwProfHoldsPositionButSwims",
      "value" = true,
      "comment" = "A character with swimming proficiency can prevent himself from moving with the current and maintain the same position in the water - but then he is effectively swimming, not treading water, and endurance is assessed accordingly.",
    }, {
      "name" = "wtwNonprofResistingSinks",
      "value" = true,
      "comment" = "A character without swimming proficiency cannot prevent himself from being carried along by the current; if he attempts to do so, he will begin to sink immediately.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['wtwProfTurnsPerEndPt']() != 2 or m['wtwNonprofRoundsPerStrPt']() != 1 or m['wtwCumCheckStep']() != 1",
      "note" = "the printed numbers: twice the endurance in turns for the proficient, the strength score in rounds for the nonproficient, the cumulative +1 check step",
    }, {
      "expr" = "m['wtwExampleStr']() != 6 or m['wtwExampleRounds']() != 12 or m['wtwExampleRounds']() != 2 * m['wtwExampleStr']() or m['wtwExampleRounds']() != m['wtwNonprofRoundsPerStrPt']() * m['wtwExampleStr']() * 2",
      "note" = "the printed example: strength 6 unencumbered treads at least 12 rounds - the strength limit doubled by the unencumbered endurance modifier (the x2 none row)",
    }, {
      "expr" = "m['wtwExampleFirstModRound']() != m['wtwExampleRounds']() + 1 or m['wtwExampleFirstModRound']() - m['wtwExampleRounds']() != 1",
      "note" = "the example cadence: the unmodified check lands at the end of the 12th round and the first +1 modifier at the end of the 13th - one round later",
    } },
  "audit" = {
      "label" = "R453 WSG treading water pin audit",
      "comment" = "The treading water slice pins the proficient calm-water hold (turns equal to twice the endurance score, one endurance point per two turns), the nonproficient limit (rounds equal to the strength score, modified for encumbrance the same way a swimmer's endurance is modified), the expiry checks (a Strength Check at expiration and every round thereafter, cumulative +1 after the first, per the 6-strength/12-round example), and the current rules (carried at the current speed modified for encumbrance, the proficient hold-position effectively swimming with endurance assessed, the nonproficient sinking immediately if he resists) (rules/wsgtread.h, prefix wtw); census 377 -> 378.",
    },
}
