-- wdf: promoted from tools/spec_r437.json (the The WSG DAMAGE FROM FALLING, R437: Table 17 (the damage from free fall or severe slope - the six fall-distance bands: 10 feet 1d6, 11-20 feet 3d6, 21-30 feet 6d6, 31-40 feet 10d6, 41-50 feet 15d6 and 51 feet or more 20d6, the maximum) with the prose rules: falling is distinguished from tumbling (the former much more liable to cause serious injury or death, the latter able in the least perilous circumstances to result in nothing more than a minor inconvenience; tumbling down a moderate or gentle slope is Table 18, the next round), falling describes a vertical drop (the character releases his hold on a cliff face or a severe slope and plummets until hitting a surface that stops the fall), the damage is 1d6 cumulative for each 10 feet fallen, the figures apply to free fall and to tumbling down a severe slope (the recurring impact with the slope plus the stop at the end), on a smooth and/or slippery slope the abrasion damage on the way down is not a great factor but the greater velocity makes the end result essentially the same as a rough slope at a slower speed, and an unimpeded fall covers 1000 feet per round in free fall or 600-800 feet per round down a severe slope depending on the texture and degree of slipperiness - the round continues the movement-across-special-terrain section. Census 361 -> 362.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 437,
  "prefix" = "wdf",
  "banner" = {
      "title" = "The WSG DAMAGE FROM FALLING, R437: Table 17 (the damage from free fall or severe slope - the six fall-distance bands: 10 feet 1d6, 11-20 feet 3d6, 21-30 feet 6d6, 31-40 feet 10d6, 41-50 feet 15d6 and 51 feet or more 20d6, the maximum) with the prose rules: falling is distinguished from tumbling (the former much more liable to cause serious injury or death, the latter able in the least perilous circumstances to result in nothing more than a minor inconvenience; tumbling down a moderate or gentle slope is Table 18, the next round), falling describes a vertical drop (the character releases his hold on a cliff face or a severe slope and plummets until hitting a surface that stops the fall), the damage is 1d6 cumulative for each 10 feet fallen, the figures apply to free fall and to tumbling down a severe slope (the recurring impact with the slope plus the stop at the end), on a smooth and/or slippery slope the abrasion damage on the way down is not a great factor but the greater velocity makes the end result essentially the same as a rough slope at a slower speed, and an unimpeded fall covers 1000 feet per round in free fall or 600-800 feet per round down a severe slope depending on the texture and degree of slipperiness - the round continues the movement-across-special-terrain section. Census 361 -> 362.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 35-36; the user own copy OCR cross-checked against the archive djvu word layer (five of six rows clean; the 11-20 feet dice cell is MISSING from the djvu text layer) and the IIIF full-resolution eye-reads (two independent reads of the full table; the disputed 3d6 cell matched the user copy exactly).",
      "sentinel" = "The Table 17 figures are cumulative damage dice by the fall-distance band - 1d6 for each 10 feet fallen, capped at the 20d6 maximum in the 51-feet-or-more band. They apply to free fall and to tumbling down a severe slope.",
    },
  "consts" = { {
      "name" = "wdfFallBandCount",
      "value" = 6,
      "comment" = "The Table 17 damage-band count (10, 11-20, 21-30, 31-40, 41-50 and 51-or-more feet).",
    }, {
      "name" = "wdfFreeFallRate",
      "value" = 1000,
      "comment" = "A character whose fall is not impeded or stopped falls 1000 feet per round in free fall.",
    }, {
      "name" = "wdfSevereRateMin",
      "value" = 600,
      "comment" = "An unimpeded fall down a severe slope covers at least 600 feet per round.",
    }, {
      "name" = "wdfSevereRateMax",
      "value" = 800,
      "comment" = "An unimpeded fall down a severe slope covers at most 800 feet per round, depending on the texture and degree of slipperiness of the slope.",
    }, {
      "name" = "wdfMaxFallDice",
      "value" = 20,
      "comment" = "The 51-feet-or-more band damage is 20d6 - the maximum.",
    } },
  "bools" = { {
      "name" = "wdfFallingVsTumbling",
      "value" = true,
      "comment" = "A distinction is made between falling and tumbling - the former is much more liable to cause serious injury or death, while the latter can in the least perilous circumstances result in nothing more than a minor inconvenience.",
    }, {
      "name" = "wdfFallingIsVerticalDrop",
      "value" = true,
      "comment" = "Falling describes a vertical drop: the character releases his hold on a cliff face or a severe slope and plummets down until hitting a surface that stops the fall.",
    }, {
      "name" = "wdfDiceCumulativePer10Ft",
      "value" = true,
      "comment" = "A character takes damage from a fall at the rate of 1d6 cumulative for each 10 feet fallen.",
    }, {
      "name" = "wdfAppliesFreeFallOrSevere",
      "value" = true,
      "comment" = "The Table 17 damage figures apply whether the character is in free fall or tumbling down a severe slope.",
    }, {
      "name" = "wdfSevereTumbleRecurringImpact",
      "value" = true,
      "comment" = "Tumbling down a severe slope, the character is assumed to take some damage from recurring impact with the slope itself, in addition to being hurt when he comes to a stop at the end of the fall.",
    }, {
      "name" = "wdfSmoothSlipperyAbrasionNote",
      "value" = true,
      "comment" = "On a smooth and/or slippery severe slope, abrasion damage on the way down is not a great factor - but the body reaches a greater velocity, so the end result is essentially the same as tumbling down a rough slope at a slower speed.",
    }, {
      "name" = "wdfTumbleModerateGentleNext",
      "value" = true,
      "comment" = "Tumbling - handled by Table 18 - is what happens to a character who slips and leaves his feet, or releases his handholds and footholds, and tumbles down a moderate or gentle slope; it is pinned by the next round.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 17: the damage from free fall or severe slope",
      "tag" = "17",
      "count" = "wdfFallBandCount",
      "col_default" = 0,
      "cols" = { "wdfFallMinFt", "wdfFallDice" },
      "col_comments" = { "The band-minimum distance of the fall in feet by band row (the 10, 11-20, 21-30, 31-40, 41-50 and 51-or-more-feet bands; the final band is open-ended).", "The cumulative damage dice for the band (1d6 for each 10 feet fallen; 20d6 is the maximum)." },
      "audit_comment" = "the Table 17 grid: the six fall-distance bands (the 10, 11-20, 21-30, 31-40, 41-50 and 51-or-more-feet bands) x the band-minimum distances and the cumulative damage dice",
      "data" = { { 10, 1 }, { 11, 3 }, { 21, 6 }, { 31, 10 }, { 41, 15 }, { 51, 20 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['wdfFallMinFt'](1) != 11 or m['wdfFallDice'](1) != 3",
      "note" = "the 11-20 feet band: 3d6 cumulative - the cell MISSING from the djvu text layer, settled by two full-res eye-reads",
    }, {
      "expr" = "m['wdfFallDice'](5) != 20 or m['wdfFallDice'](5) != m['wdfMaxFallDice']()",
      "note" = "the 51-feet-or-more band is capped at the 20d6 maximum",
    }, {
      "expr" = "m['wdfFreeFallRate']() != 1000 or m['wdfSevereRateMin']() + m['wdfSevereRateMax']() != 1400",
      "note" = "the unimpeded rates: 1000 feet per round in free fall, 600 through 800 feet per round down a severe slope (the 600 plus the 800 span 1400)",
    }, {
      "expr" = "m['wdfFallDice'](1) - m['wdfFallDice'](0) * 3 != 0",
      "note" = "the first two bands: 3d6 at 20 feet is three times the 1d6 at 10 feet",
    } },
  "audit" = {
      "label" = "R437 WSG falling damage pin audit",
      "comment" = "The damage-from-falling slice pins Table 17 (the six fall-distance bands x the band-minimum distances and the cumulative damage dice) with the falling-vs-tumbling prose (the vertical-drop definition, the 1d6-cumulative-per-10-feet basis, the recurring-impact rule on severe slopes, the smooth/slippery abrasion note and the 1000 and 600-800 feet-per-round rates) (rules/wsgfall.h, prefix wdf); census 361 -> 362.",
    },
}
