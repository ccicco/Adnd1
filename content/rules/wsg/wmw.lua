-- wmw: promoted from tools/spec_r451.json (the The WSG OTHER EFFECTS OF MOVING WATER, R451: the rough-water prose (no table this round) - a shallow river or stream in which the water is moving rapidly can harm characters by buffeting them against rocks and other protrusions. As outlined in the Dungeoneer's Survival Guide, the DM attaches a rating of from 1 to 10 to a shallow, rapidly coursing stream or river, with 1 being the most hazardous; the number is the amount of time, in ROUNDS, that a swimmer can traverse the water before needing a Proficiency Check - a rating of 1 means a check every round, a rating of 5 means a check on the first round, the sixth round and every fifth round thereafter. Failure means the swimmer has been thrown against the rocks, suffering 1d6 points of damage; a character without swimming proficiency is virtually helpless in similar circumstances and suffers 1d3 points of damage every round he remains in the water. Any character can halt his movement through rough water by grabbing onto a handy protrusion (a big rock, an overhanging tree limb), if one is available and within reach - a successful Dexterity Check, with a new attempt every round if desired; after catching on, a successful Strength Check once every TWO rounds to remain attached, failure meaning he has lost his grip and is again being swept downstream. The waterfall rules: carried over a waterfall of 40 feet or more, he suffers falling damage equal to ONE-HALF the normal free-fall amount - but a saving throw versus breath weapon is allowed: on a successful save with the fall at least 40 but not more than 100 feet, no damage; on a successful save beyond 100 feet, one-tenth of normal falling damage (rounded up); under 40 feet, no falling damage at all - the fall is treated as a normal dive. These guidelines assume the base of the waterfall is free of rocks: a plunge into rocks is assessed as a fall through the air. Census 375 -> 376.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 451,
  "prefix" = "wmw",
  "banner" = {
      "title" = "The WSG OTHER EFFECTS OF MOVING WATER, R451: the rough-water prose (no table this round) - a shallow river or stream in which the water is moving rapidly can harm characters by buffeting them against rocks and other protrusions. As outlined in the Dungeoneer's Survival Guide, the DM attaches a rating of from 1 to 10 to a shallow, rapidly coursing stream or river, with 1 being the most hazardous; the number is the amount of time, in ROUNDS, that a swimmer can traverse the water before needing a Proficiency Check - a rating of 1 means a check every round, a rating of 5 means a check on the first round, the sixth round and every fifth round thereafter. Failure means the swimmer has been thrown against the rocks, suffering 1d6 points of damage; a character without swimming proficiency is virtually helpless in similar circumstances and suffers 1d3 points of damage every round he remains in the water. Any character can halt his movement through rough water by grabbing onto a handy protrusion (a big rock, an overhanging tree limb), if one is available and within reach - a successful Dexterity Check, with a new attempt every round if desired; after catching on, a successful Strength Check once every TWO rounds to remain attached, failure meaning he has lost his grip and is again being swept downstream. The waterfall rules: carried over a waterfall of 40 feet or more, he suffers falling damage equal to ONE-HALF the normal free-fall amount - but a saving throw versus breath weapon is allowed: on a successful save with the fall at least 40 but not more than 100 feet, no damage; on a successful save beyond 100 feet, one-tenth of normal falling damage (rounded up); under 40 feet, no falling damage at all - the fall is treated as a normal dive. These guidelines assume the base of the waterfall is free of rocks: a plunge into rocks is assessed as a fall through the air. Census 375 -> 376.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 42; the user own copy OCR (page 43) cross-checked against the archive djvu word layer (Guide_0042.djvu) - the section reads CLEAN two-way, every number (the 1-10 rating, the two damage dice, the two-round strength cadence, the 40/100 foot thresholds, the one-half and one-tenth divisors) matched exactly; no eye-reads were needed.",
      "sentinel" = "Rate the rapid stream 1 to 10 and check swimming that often; fail and the rocks take 1d6 - or 1d3 a round for the helpless nonproficient. Grab a protrusion on a Dex check, hold it on a Strength check every two rounds, and go over a waterfall at half damage - saved at 40 to 100 feet for nothing, beyond that for a tenth, under 40 for a clean dive, unless the rocks at the bottom void the mercy.",
    },
  "consts" = { {
      "name" = "wmwStreamRateMin",
      "value" = 1,
      "comment" = "The Dungeon Master attaches a rating of from 1 to 10 to a shallow, rapidly coursing stream or river, with 1 being the most hazardous.",
    }, {
      "name" = "wmwStreamRateMax",
      "value" = 10,
      "comment" = "The top of the stream hazard rating range: 1 to 10, with 1 the most hazardous.",
    }, {
      "name" = "wmwBuffetDmgDie",
      "value" = 6,
      "comment" = "Failure on the moving-water proficiency check indicates that the swimmer has been thrown against the rocks, suffering 1d6 points of damage.",
    }, {
      "name" = "wmwNonprofDmgDie",
      "value" = 3,
      "comment" = "A character without swimming proficiency is virtually helpless in similar circumstances, and will suffer 1d3 points of damage every round that he remains in the water.",
    }, {
      "name" = "wmwHoldCheckPeriod",
      "value" = 2,
      "comment" = "After catching onto a protrusion, the character must make a successful Strength Check once every two rounds to remain attached; failure indicates he has lost his grip and is again being swept downstream.",
    }, {
      "name" = "wmwFallDamageDiv",
      "value" = 2,
      "comment" = "A character carried over a waterfall of 40 feet or more suffers falling damage equal to one-half of the amount that would be taken in a normal free fall.",
    }, {
      "name" = "wmwFallSaveMinFt",
      "value" = 40,
      "comment" = "The 40-foot threshold: at 40 feet or more the half-damage rule applies, and a successful breath-weapon save over a fall of at least 40 but not more than 100 feet means no damage at all.",
    }, {
      "name" = "wmwFallSaveMaxFt",
      "value" = 100,
      "comment" = "The 100-foot threshold: a successful save on a fall greater than 100 feet reduces the damage to one-tenth of normal (rounded up).",
    }, {
      "name" = "wmwLongFallDiv",
      "value" = 10,
      "comment" = "If the save succeeds and the fall is greater than 100 feet, the character takes one-tenth of normal falling damage, rounded up.",
    } },
  "bools" = { {
      "name" = "wmwRatingIsCheckCadence",
      "value" = true,
      "comment" = "The hazard rating is the amount of time, in rounds, that a swimmer can traverse the water before needing a Proficiency Check - in a stream with a rating of 1 a check must be made every round, and in a stream with a rating of 5 a check is made on the first round, the sixth round, and every fifth round thereafter.",
    }, {
      "name" = "wmwBuffetingMechanism",
      "value" = true,
      "comment" = "A shallow river or stream in which the water is moving rapidly can harm characters by buffeting them against rocks and other protrusions in the water.",
    }, {
      "name" = "wmwNonproficientHelpless",
      "value" = true,
      "comment" = "A character without swimming proficiency is virtually helpless in rapidly moving water.",
    }, {
      "name" = "wmwGrabDexCheck",
      "value" = true,
      "comment" = "Any character can halt his movement through rough water by grabbing onto a handy protrusion (a big rock, an overhanging tree limb), assuming such protrusions are available and within reach - the tactic succeeds on a successful Dexterity Check.",
    }, {
      "name" = "wmwGrabRetryEveryRound",
      "value" = true,
      "comment" = "A new attempt at grabbing a protrusion can be made every round if desired.",
    }, {
      "name" = "wmwHoldStrengthCheck",
      "value" = true,
      "comment" = "After catching onto something, the character must make a successful Strength Check once every two rounds to remain attached; failure means he has lost his grip and is again being swept downstream.",
    }, {
      "name" = "wmwWaterfallSaveVsBreath",
      "value" = true,
      "comment" = "A character carried over a waterfall of 40 feet or more is allowed a saving throw versus breath weapon.",
    }, {
      "name" = "wmwSaveShortFallNoDamage",
      "value" = true,
      "comment" = "If the save succeeds and the fall covers at least 40 feet but not more than 100 feet, the character takes no damage.",
    }, {
      "name" = "wmwSaveLongFallTenth",
      "value" = true,
      "comment" = "If the save succeeds and the fall is greater than 100 feet, the character takes one-tenth of normal falling damage, rounded up.",
    }, {
      "name" = "wmwShortFallTreatedAsDive",
      "value" = true,
      "comment" = "No falling damage is suffered by a character carried over a waterfall less than 40 feet high; in such a case the fall is treated as a normal dive.",
    }, {
      "name" = "wmwRocksVoidMercy",
      "value" = true,
      "comment" = "The waterfall guidelines assume the base does not contain rocks or other obstructions; if a plunge over a waterfall sends the character crashing into rocks, falling damage is assessed as for a fall through the air.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['wmwStreamRateMin']() != 1 or m['wmwStreamRateMax']() != 10 or m['wmwBuffetDmgDie']() != 6 or m['wmwNonprofDmgDie']() != 3",
      "note" = "the printed hazard numbers: the 1-10 rating, the 1d6 buffeting damage, the 1d3 nonproficient damage",
    }, {
      "expr" = "m['wmwFallSaveMinFt']() != 40 or m['wmwFallSaveMaxFt']() != 100 or m['wmwFallDamageDiv']() != 2 or m['wmwLongFallDiv']() != 10",
      "note" = "the waterfall numbers: the 40/100 foot thresholds, the one-half base damage, the one-tenth saved damage beyond 100 feet",
    }, {
      "expr" = "m['wmwFallSaveMaxFt']() != 2 * m['wmwFallSaveMinFt']() + 20 or m['wmwLongFallDiv']() != 5 * m['wmwFallDamageDiv']()",
      "note" = "the waterfall arithmetic anchor: the long threshold is twice the short plus twenty, and the saved long divisor is five times the unsaved short divisor",
    }, {
      "expr" = "m['wmwHoldCheckPeriod']() != 2 or m['wmwBuffetDmgDie']() != 2 * m['wmwNonprofDmgDie']()",
      "note" = "the two-round strength cadence, and the buffeting die is twice the nonproficient die",
    } },
  "audit" = {
      "label" = "R451 WSG moving water pin audit",
      "comment" = "The moving water slice pins the 1-10 stream hazard rating as the proficiency-check cadence (rating 1 = every round, rating 5 = rounds 1, 6, 11...), the 1d6 buffeting damage on a failed check, the virtually helpless nonproficient swimmer at 1d3 damage per round, the grab-a-protrusion halt (a Dex check, retried every round, then a Strength check every two rounds to stay attached), and the waterfall rules (half falling damage at 40 feet or more, the breath-weapon save with no damage at 40-100 feet and one-tenth rounded up beyond 100, the under-40 fall treated as a normal dive, and rocks at the base assessed as a fall through the air) (rules/wsgmwater.h, prefix wmw); census 375 -> 376.",
    },
}
