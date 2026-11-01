-- wcc: promoted from tools/spec_r466.json (the R466: the WSG CONSUMING AND CARRYING FOOD slice - the ration ladder (one fish half a ration, one size S animal a full ration, one size M animal feeding three characters for a day, one size L animal six rations, at least twenty rations for a full day of expert butchering), the druid disapproval of intentional overkill with the feed-three excuse, carrying the excess subject only to encumbrance and spoilage, and Table 33: the food spoilage grid by effective temperature with the taint and spoil mechanics, printed p. 58.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 466,
  "prefix" = "wcc",
  "banner" = {
      "title" = "R466: the WSG CONSUMING AND CARRYING FOOD slice - the ration ladder (one fish half a ration, one size S animal a full ration, one size M animal feeding three characters for a day, one size L animal six rations, at least twenty rations for a full day of expert butchering), the druid disapproval of intentional overkill with the feed-three excuse, carrying the excess subject only to encumbrance and spoilage, and Table 33: the food spoilage grid by effective temperature with the taint and spoil mechanics, printed p. 58.",
      "provenance" = "Ground truth two-way: the pdfy embedded OCR text layer of the printed p. 58 content stream (the FlateDecode stream of pageobj 549, decompressed and position-read) vs the djvu word layer (Guide_0058), with the arithmetic ladders as the tiebreaker. Both layers agree on every Table 33 value cell except the green-plants 31-50 cell, where the pdfy reads 6/20 against a djvu garble; 6/20 fits the clean days ladder (6, 4, 2, 1) and the pct ladder (20, 30, 40, 50). The below-30 column is a dash in every row (both layers garble the dash glyph); the book explanation sentence - spoilage will not occur as long as the effective temperature remains within this range - confirms the dash, and continually frozen food keeps indefinitely no matter how long it is carried. The printed p. 58 image shows scanner double-imaging (a ghost copy about 12 pixels below the true print) which defeated the pixel and vision reads; the text layers carry the table. The mechanics: the effective temperature is the warmest category applying at least one hour that day, a category once used ratchets to the same or warmer for all later checks, thawed food is subject to spoilage from the thaw day (counted as day 1) even if promptly re-frozen; one failed check taints (a secret Wisdom Check to notice, eatable anyway, a CON check at +4 to avoid nausea and cramps within 1d10+10 minutes, a -1 penalty on attacks and dodging or maneuvering saves for 12 hours, then an unmodified CON check per hour to recover, tainted food still a full ration); a second failed check obviously spoils (CON check at +10, penalties at least 24 hours if stricken, else a 50% chance the food still provides the full or half ration value, otherwise no nourishment at all). The onset window is 11-20 minutes (1d10+10). The gluttony and indigestion note: the rules do not account for them.",
      "sentinel" = "All 40 Table 33 cells pinned (the max days and the spoilage pct per food type per temperature band); the ration ladder and the taint and spoil mechanics are audit examples, including the dash column and the frozen and thaw rules.",
    },
  "consts" = { {
      "name" = "wccRowCount",
      "value" = 4,
      "comment" = "the Table 33 row count: green plants, fruits or vegetables, cooked meat, raw meat",
    }, {
      "name" = "wccFishRationNum",
      "value" = 1,
      "comment" = "one fish provides half of a character minimum daily ration: the numerator",
    }, {
      "name" = "wccFishRationDen",
      "value" = 2,
      "comment" = "the fish half-ration denominator",
    }, {
      "name" = "wccSizeSRations",
      "value" = 1,
      "comment" = "one size S animal is one full ration",
    }, {
      "name" = "wccSizeMFeedCount",
      "value" = 3,
      "comment" = "one size M animal is enough to feed three characters for one day",
    }, {
      "name" = "wccSizeLRations",
      "value" = 6,
      "comment" = "one size L animal is six rations worth of food",
    }, {
      "name" = "wccButcherRations",
      "value" = 20,
      "comment" = "at least twenty full rations from a size L carcass with expert butchering",
    }, {
      "name" = "wccButcherDays",
      "value" = 1,
      "comment" = "the expert butchering takes one full day of butchering, slicing and packaging",
    }, {
      "name" = "wccOverkillFeedCount",
      "value" = 3,
      "comment" = "killing one size L animal to feed himself and two others is an excusable overkill",
    }, {
      "name" = "wccTempHourGate",
      "value" = 1,
      "comment" = "a temperature category applies as the effective temperature only if it held for at least one hour on that day",
    }, {
      "name" = "wccThawStartDay",
      "value" = 1,
      "comment" = "thawed food is subject to spoilage beginning on the thaw day, counting that day as day 1",
    }, {
      "name" = "wccTaintConMod",
      "value" = 4,
      "comment" = "eating tainted food demands a Constitution check with a +4 modifier to avoid suffering",
    }, {
      "name" = "wccTaintOnsetDie",
      "value" = 10,
      "comment" = "the tainted-food onset die: 1d10",
    }, {
      "name" = "wccTaintOnsetBase",
      "value" = 10,
      "comment" = "the tainted-food onset base: nausea and cramps within 1d10+10, the 11-20 minute window",
    }, {
      "name" = "wccTaintAtkPenalty",
      "value" = 1,
      "comment" = "the tainted-food penalty: -1 on all attack rolls and on dodging or maneuvering saves",
    }, {
      "name" = "wccTaintPenaltyHours",
      "value" = 12,
      "comment" = "the tainted-food penalty lasts for 12 hours",
    }, {
      "name" = "wccTaintRecheckMins",
      "value" = 60,
      "comment" = "after the 12 hours, recovery checks come at one per hour until one succeeds",
    }, {
      "name" = "wccSpoilConMod",
      "value" = 10,
      "comment" = "eating spoiled food demands a Constitution check with a +10 modifier to avoid the illness",
    }, {
      "name" = "wccSpoilPenaltyHours",
      "value" = 24,
      "comment" = "if stricken by spoiled food, the penalties last at least 24 hours instead of 12",
    }, {
      "name" = "wccSpoilRationPct",
      "value" = 50,
      "comment" = "if spoiled food causes no illness, a 50% chance it still provides the full ration value (or half, if only that much was eaten)",
    } },
  "bools" = { {
      "name" = "wccGluttonyNotModeled",
      "value" = true,
      "comment" = "these rules do not account for gluttony or indigestion - that is left to the Dungeon Master",
    }, {
      "name" = "wccDruidDisapprovesOverkill",
      "value" = true,
      "comment" = "a druid in the party strongly disapproves if hunters or fishermen intentionally kill more than they can conceivably eat in one sitting",
    }, {
      "name" = "wccOverkillExcusable",
      "value" = true,
      "comment" = "an overkill cannot always be helped: the hunter feeding three is not held responsible for the leftovers",
    }, {
      "name" = "wccExcessCarryAllowed",
      "value" = true,
      "comment" = "excess food need not be left behind when the party breaks camp - it can be carried along",
    }, {
      "name" = "wccEncumbranceDMCall",
      "value" = true,
      "comment" = "encumbrance, the first of the two carrying factors, is a Dungeon Master ruling",
    }, {
      "name" = "wccDashNoSpoilage",
      "value" = true,
      "comment" = "the Table 33 dash: spoilage will not occur as long as the effective temperature remains within the below-30 range",
    }, {
      "name" = "wccFrozenKeepsIndefinitely",
      "value" = true,
      "comment" = "food kept continually frozen will be good to eat no matter how long it is carried or stored",
    }, {
      "name" = "wccThawSpoilsEvenIfRefrozen",
      "value" = true,
      "comment" = "thawed food is subject to spoilage from the thaw day even if promptly re-frozen after the exposure",
    }, {
      "name" = "wccWarmestCategoryApplies",
      "value" = true,
      "comment" = "the effective temperature is the warmest category that applied on the given day, gated by the one-hour rule",
    }, {
      "name" = "wccCategoryRatchet",
      "value" = true,
      "comment" = "once a temperature category is used for one spoilage check, the same or a warmer one is used for all subsequent checks",
    }, {
      "name" = "wccOneFailTainted",
      "value" = true,
      "comment" = "food that fails one spoilage check is tainted - not as good as fresh, but not obviously spoiled",
    }, {
      "name" = "wccTaintSecretWisdomCheck",
      "value" = true,
      "comment" = "a character intending to eat tainted food gets a secret Wisdom Check to notice the spoilage first",
    }, {
      "name" = "wccMayEatAnyway",
      "value" = true,
      "comment" = "a character who notices the taint may choose to eat the food anyway",
    }, {
      "name" = "wccTwoFailsSpoiled",
      "value" = true,
      "comment" = "food that fails a second spoilage check is obviously spoiled and perceived as such by anyone intending to eat it",
    }, {
      "name" = "wccTaintFullRationValue",
      "value" = true,
      "comment" = "tainted food still provides a normal amount of food value: a full ration still counts as a full ration",
    }, {
      "name" = "wccSpoiledHalfRationIfHalfEaten",
      "value" = true,
      "comment" = "if only half of the no-illness spoiled food was eaten, it counts as a half-ration",
    }, {
      "name" = "wccSpoiledNoNourishment",
      "value" = true,
      "comment" = "otherwise the spoiled food is so spoiled it does not serve as nourishment - as if not eaten at all",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "wccSpoilage",
      "tag" = "33",
      "count" = "wccRowCount",
      "cols" = { "wccBelowDays", "wccBelowPct", "wcc31Days", "wcc31Pct", "wcc51Days", "wcc51Pct", "wcc71Days", "wcc71Pct", "wccAboveDays", "wccAbovePct" },
      "col_default" = 0,
      "col_comments" = { "the Table 33 below-30 max days (the dash)", "the Table 33 below-30 spoilage pct (the dash)", "the Table 33 31-50 max days", "the Table 33 31-50 spoilage pct", "the Table 33 51-70 max days", "the Table 33 51-70 spoilage pct", "the Table 33 71-90 max days", "the Table 33 71-90 spoilage pct", "the Table 33 above-90 max days", "the Table 33 above-90 spoilage pct" },
      "row_comments" = { "the green plants row", "the fruits or vegetables row", "the cooked meat row", "the raw meat row" },
      "data" = { { 0, 0, 6, 20, 4, 30, 2, 40, 1, 50 }, { 0, 0, 5, 30, 3, 40, 2, 50, 1, 60 }, { 0, 0, 3, 20, 2, 50, 1, 60, 1, 80 }, { 0, 0, 2, 50, 1, 70, 1, 80, 1, 90 } },
      "audit_comment" = "the Table 33 food spoilage grid (the max days kept before the first check, then the pct spoilage chance per subsequent day, per food type per effective temperature band)",
    } },
  "chains" = {},
  "examples" = { {
      "note" = "the green plants row: dash below 30, then 6/20, 4/30, 2/40, 1/50",
      "expr" = "m['wccBelowDays'](0) != 0 or m['wccBelowPct'](0) != 0 or m['wcc31Days'](0) != 6 or m['wcc31Pct'](0) != 20 or m['wcc51Days'](0) != 4 or m['wcc51Pct'](0) != 30 or m['wcc71Days'](0) != 2 or m['wcc71Pct'](0) != 40 or m['wccAboveDays'](0) != 1 or m['wccAbovePct'](0) != 50",
    }, {
      "note" = "the fruits or vegetables row: dash below 30, then 5/30, 3/40, 2/50, 1/60",
      "expr" = "m['wccBelowDays'](1) != 0 or m['wccBelowPct'](1) != 0 or m['wcc31Days'](1) != 5 or m['wcc31Pct'](1) != 30 or m['wcc51Days'](1) != 3 or m['wcc51Pct'](1) != 40 or m['wcc71Days'](1) != 2 or m['wcc71Pct'](1) != 50 or m['wccAboveDays'](1) != 1 or m['wccAbovePct'](1) != 60",
    }, {
      "note" = "the cooked meat row: dash below 30, then 3/20, 2/50, 1/60, 1/80",
      "expr" = "m['wccBelowDays'](2) != 0 or m['wccBelowPct'](2) != 0 or m['wcc31Days'](2) != 3 or m['wcc31Pct'](2) != 20 or m['wcc51Days'](2) != 2 or m['wcc51Pct'](2) != 50 or m['wcc71Days'](2) != 1 or m['wcc71Pct'](2) != 60 or m['wccAboveDays'](2) != 1 or m['wccAbovePct'](2) != 80",
    }, {
      "note" = "the raw meat row: dash below 30, then 2/50, 1/70, 1/80, 1/90",
      "expr" = "m['wccBelowDays'](3) != 0 or m['wccBelowPct'](3) != 0 or m['wcc31Days'](3) != 2 or m['wcc31Pct'](3) != 50 or m['wcc51Days'](3) != 1 or m['wcc51Pct'](3) != 70 or m['wcc71Days'](3) != 1 or m['wcc71Pct'](3) != 80 or m['wccAboveDays'](3) != 1 or m['wccAbovePct'](3) != 90",
    }, {
      "note" = "one fish is half a ration (cross-multiplied)",
      "expr" = "2 * m['wccFishRationNum']() != m['wccFishRationDen']()",
    }, {
      "note" = "the ration ladder: one size S a full ration, one size M feeds three, one size L six rations",
      "expr" = "m['wccSizeSRations']() != 1 or m['wccSizeMFeedCount']() != 3 or m['wccSizeLRations']() != 6",
    }, {
      "note" = "the expert butchering: one full day yields at least twenty full rations",
      "expr" = "m['wccButcherRations']() != 20 or m['wccButcherDays']() != 1",
    }, {
      "note" = "the excusable overkill: one size L kill feeding the hunter and two others",
      "expr" = "m['wccOverkillFeedCount']() != 3 or m['wccSizeLRations']() != 6",
    }, {
      "note" = "the tainted-food onset: nausea and cramps within 1d10+10 minutes, the 11-20 window",
      "expr" = "m['wccTaintOnsetDie']() + m['wccTaintOnsetBase']() != 20 or m['wccTaintOnsetBase']() != 10",
    }, {
      "note" = "the Constitution modifiers: +4 for tainted food, +10 for spoiled",
      "expr" = "m['wccTaintConMod']() != 4 or m['wccSpoilConMod']() != 10",
    }, {
      "note" = "the penalty durations: 12 hours tainted, at least 24 hours spoiled",
      "expr" = "m['wccTaintPenaltyHours']() != 12 or m['wccSpoilPenaltyHours']() != 24",
    }, {
      "note" = "the tainted-food penalty: -1 on attack rolls and dodging or maneuvering saves, one recovery check per hour",
      "expr" = "m['wccTaintAtkPenalty']() != 1 or m['wccTaintRecheckMins']() != 60",
    }, {
      "note" = "the effective-temperature gates: the one-hour rule and the thaw day counted as day 1",
      "expr" = "m['wccTempHourGate']() != 1 or m['wccThawStartDay']() != 1",
    }, {
      "note" = "the no-illness spoiled ration: a 50% chance of the full or half ration value",
      "expr" = "m['wccSpoilRationPct']() != 50",
    } },
  "audit" = {
      "label" = "R466 WSG food carrying pin audit",
      "comment" = "The Table 33 spoilage grid cell by cell (the max days and the pct per food type per temperature band), the ration ladder (the fish half ration, the size S/M/L rations, the twenty-ration butchering) and the spoilage mechanics (the warmest-category rule, the ratchet, the frozen and thaw rules, the taint and spoil CON modifiers and penalties, the ration-value chance) - every cell, const and bool verified against the model.",
    },
}
