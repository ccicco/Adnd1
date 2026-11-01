-- wdt: promoted from tools/spec_r438.json (the The WSG TUMBLING DAMAGE, R438: Table 18 (the damage from tumbling down a moderate or gentle slope - the six rows x the non-slippery, slightly slippery and slippery conditions, each entry the abrasion-free feet / the abrasion die / the impact distance, from the rough gentle 20/3/50 to the smooth moderate 50/3/20) with the prose rules: tumbling is what happens to a character who slips and leaves his feet, or releases his handholds and footholds, and tumbles down a moderate or gentle slope; the first number is the feet tumbled free of abrasion damage, the second is the die rolled (6 = 1d6, 3 = 1d3) per 10 feet past that, the third is the minimum distance for impact damage (1d6 per full or partial increment of that distance at the stop); the impact figures are the worst-case abrupt stop (a gradual stop decreases the damage, perhaps eliminating it; a long flat-terrain tumble can add abrasion); and an unimpeded tumble covers 100-300 feet per round down a gentle slope and 300-500 feet per round down a moderate slope, slowest when nonslippery - the round continues the movement-across-special-terrain section. Census 362 -> 363.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 438,
  "prefix" = "wdt",
  "banner" = {
      "title" = "The WSG TUMBLING DAMAGE, R438: Table 18 (the damage from tumbling down a moderate or gentle slope - the six rows x the non-slippery, slightly slippery and slippery conditions, each entry the abrasion-free feet / the abrasion die / the impact distance, from the rough gentle 20/3/50 to the smooth moderate 50/3/20) with the prose rules: tumbling is what happens to a character who slips and leaves his feet, or releases his handholds and footholds, and tumbles down a moderate or gentle slope; the first number is the feet tumbled free of abrasion damage, the second is the die rolled (6 = 1d6, 3 = 1d3) per 10 feet past that, the third is the minimum distance for impact damage (1d6 per full or partial increment of that distance at the stop); the impact figures are the worst-case abrupt stop (a gradual stop decreases the damage, perhaps eliminating it; a long flat-terrain tumble can add abrasion); and an unimpeded tumble covers 100-300 feet per round down a gentle slope and 300-500 feet per round down a moderate slope, slowest when nonslippery - the round continues the movement-across-special-terrain section. Census 362 -> 363.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 36; the user own copy OCR cross-checked against the archive djvu word layer (16 of 18 cells clean; the normal gentle and normal moderate slippery cells are garbled or absent from the djvu) and the IIIF full-resolution eye-reads (two independent reads of the two disputed rows; every value matched the user copy exactly: 50/3/30 and 40/6/20). The smooth moderate die is genuinely 3 - the djvu word layer confirms the 1d3 there.",
      "sentinel" = "Each Table 18 entry is three numbers: the feet tumbled before abrasion damage begins, the abrasion die rolled per 10 feet beyond that, and the minimum distance for the 1d6-per-increment impact damage of the stop.",
    },
  "consts" = { {
      "name" = "wdtRowCount",
      "value" = 6,
      "comment" = "The Table 18 row count (the rough, normal and smooth surfaces at the gentle and moderate tilts).",
    }, {
      "name" = "wdtGentleRowBase",
      "value" = 0,
      "comment" = "The gentle-slope rows begin at index 0 (the rough, normal and smooth gentle rows).",
    }, {
      "name" = "wdtModerateRowBase",
      "value" = 3,
      "comment" = "The moderate-slope rows begin at index 3 (the rough, normal and smooth moderate rows).",
    }, {
      "name" = "wdtAbrasionPerFt",
      "value" = 10,
      "comment" = "Abrasion damage is rolled for every 10 feet of distance greater than the first number of the entry.",
    }, {
      "name" = "wdtGentleRateMin",
      "value" = 100,
      "comment" = "An unimpeded tumble down a gentle slope covers at least 100 feet in one round.",
    }, {
      "name" = "wdtGentleRateMax",
      "value" = 300,
      "comment" = "An unimpeded tumble down a gentle slope covers at most 300 feet in one round.",
    }, {
      "name" = "wdtModerateRateMin",
      "value" = 300,
      "comment" = "An unimpeded tumble down a moderate slope covers at least 300 feet per round.",
    }, {
      "name" = "wdtModerateRateMax",
      "value" = 500,
      "comment" = "An unimpeded tumble down a moderate slope covers at most 500 feet per round.",
    } },
  "bools" = { {
      "name" = "wdtFirstNumberFreeFeet",
      "value" = true,
      "comment" = "The first number of a Table 18 entry is the distance in feet a character can tumble down the slope before taking damage from abrasion.",
    }, {
      "name" = "wdtSecondNumberDie",
      "value" = true,
      "comment" = "The second number of an entry is the die that is rolled (6 = 1d6, 3 = 1d3) to determine abrasion damage for every 10 feet of distance greater than the first number.",
    }, {
      "name" = "wdtThirdNumberImpactDist",
      "value" = true,
      "comment" = "The third number of an entry is the minimum distance the character must travel in order to take damage from the impact of the stop at the end of his tumble.",
    }, {
      "name" = "wdtImpactPerIncrement",
      "value" = true,
      "comment" = "Impact damage is 1d6 for a tumble of the indicated distance, and an additional 1d6 for each full or partial increment of that distance.",
    }, {
      "name" = "wdtImpactWorstCase",
      "value" = true,
      "comment" = "The impact figures represent a worst-case situation - when the character comes to an abrupt stop at the bottom of the slope.",
    }, {
      "name" = "wdtGradualStopDecrease",
      "value" = true,
      "comment" = "If the topography lets the character come to a gradual stop (such as tumbling onto a large expanse of flat, featureless terrain), the DM should decrease impact damage accordingly - perhaps eliminating it altogether.",
    }, {
      "name" = "wdtFlatTumbleExtraAbrasion",
      "value" = true,
      "comment" = "If the character tumbles across flat terrain for some length of time before gradually stopping, the DM could assess some additional abrasion damage to account for the extra distance of the fall.",
    }, {
      "name" = "wdtTumbleIsSlipOrRelease",
      "value" = true,
      "comment" = "Tumbling is what happens to a character who slips and leaves his feet, or releases handholds and footholds, and tumbles down a moderate or gentle slope.",
    }, {
      "name" = "wdtRatesSlowestNonslippery",
      "value" = true,
      "comment" = "The tumble rates depend on the slipperiness of the surface - the slowest rate applies to a nonslippery surface.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 18: the damage from tumbling down a moderate or gentle slope",
      "tag" = "18",
      "count" = "wdtRowCount",
      "col_default" = 0,
      "cols" = { "wdtAbrN", "wdtAbrS", "wdtAbrV", "wdtDieN", "wdtDieS", "wdtDieV", "wdtImpN", "wdtImpS", "wdtImpV" },
      "col_comments" = { "The abrasion-free distance in feet for the non-slippery condition, by surface row (the rough, normal and smooth surfaces at the gentle and moderate tilts).", "The abrasion-free distance in feet for the slightly slippery condition.", "The abrasion-free distance in feet for the slippery condition.", "The abrasion die for the non-slippery condition (6 = 1d6, 3 = 1d3, rolled per 10 feet past the free distance).", "The abrasion die for the slightly slippery condition.", "The abrasion die for the slippery condition.", "The minimum impact distance in feet for the non-slippery condition (1d6 impact damage per full or partial increment).", "The minimum impact distance in feet for the slightly slippery condition.", "The minimum impact distance in feet for the slippery condition." },
      "audit_comment" = "the Table 18 grid: the six slope rows (the rough, normal and smooth surfaces at the gentle and moderate tilts) x the three conditions, each cell split into the abrasion-free feet, the abrasion die and the impact distance",
      "data" = { { 20, 30, 40, 3, 3, 3, 50, 40, 30 }, { 10, 20, 30, 6, 6, 6, 40, 30, 20 }, { 30, 40, 50, 3, 3, 3, 50, 40, 30 }, { 20, 30, 40, 6, 6, 6, 40, 30, 20 }, { 40, 50, 60, 3, 3, 3, 40, 30, 30 }, { 30, 40, 50, 3, 3, 3, 30, 20, 20 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['wdtAbrN'](0) != 20 or m['wdtDieN'](0) != 3 or m['wdtImpN'](0) != 50",
      "note" = "the rough gentle non-slippery cell: 20 feet free of abrasion, a 1d3 die, a 50-foot impact threshold",
    }, {
      "expr" = "(100 - m['wdtAbrS'](5)) != m['wdtAbrasionPerFt']() * 6 or m['wdtDieS'](5) != 3",
      "note" = "the book's own worked example: the smooth moderate slightly-slippery 40/3/20 cell - a 100-foot tumble suffers 6d3 abrasion over the last 60 feet (written division-free - 100 minus 40 equals six 10-foot increments)",
    }, {
      "expr" = "m['wdtImpS'](5) * 5 != 100 or m['wdtImpS'](5) != 20",
      "note" = "the same example, the impact half: five 20-foot increments in 100 feet means 5d6 impact damage at the bottom (written division-free)",
    }, {
      "expr" = "m['wdtGentleRateMin']() != 100 or m['wdtModerateRateMax']() != 500",
      "note" = "the unimpeded tumble rates: 100-300 feet per round down a gentle slope, 300-500 feet per round down a moderate slope",
    }, {
      "expr" = "m['wdtDieN'](1) != 6 or m['wdtDieN'](5) != 3",
      "note" = "the die split: the rough moderate row rolls 1d6 abrasion, the smooth moderate row rolls 1d3 (the book itself uses the 3 there)",
    } },
  "audit" = {
      "label" = "R438 WSG tumbling damage pin audit",
      "comment" = "The tumbling-damage slice pins Table 18 (the six moderate-or-gentle slope rows x the three condition cells, each split into the abrasion-free feet, the abrasion die and the impact distance) with the entry format rules, the worst-case and gradual-stop impact rules, the flat-terrain extra-abrasion rule and the tumble rates (rules/wsgtumble.h, prefix wdt); census 362 -> 363.",
    },
}
