-- wrs: promoted from tools/spec_r473.json (the R473: the WSG PORTABLE SHELTER MECHANICS and REST AND COMFORT slice with TABLE 37 - the shelter kits (the poor covering loosely stitched of several pieces with wind through the seams and no anchoring gear or rope provided, what an unskilled maker ends up with; the adequate kit of at least two poles - a backbone ridgepole and a cross-brace - with tighter stitching and stakes driven through the covering edges; the good kit of at least four poles with the covering pieces stitched tightly and overlapped like shingles so no seams are exposed and reinforced edge holes for damage-free anchoring; the superior kit of at least six poles making a strong frame, a tailored covering of as few pieces as possible with reinforced seams - a true structure, the next best thing to a miner's shack), the occupancy (a small shelter one human-sized or two smaller characters plus all their gear, twice as many in close quarters; a medium two human-sized, twice as many close; a large four by design, five or six sleeping with gear stored outside, seven or eight in close quarters and no more than eight), the setup and takedown discipline (a second character reducing setup by 1 turn; a rope use proficient character halving the setup time rounded up with or without help; the 1/2/3-turn setup minimums by size; the takedown in 1 turn less than setup regardless of helpers, halved by rope use proficiency, with the 5-round/1-turn/2-turn minimums; the poor and adequate kits assuming the characters bring their own rope), the moisture rule (precip heavier than the value gets through as a storm one step lighter; a superior shelter protecting from even a downpour unless the wind is too strong or the storm separates it from its moorings), the wind rules (the greatest velocity withstood without leaking; every 10 mph above the number a 5 mph wind felt inside; above twice the number a 25% chance per 10 mph each hour of wind damage leaving the shelter useless until repaired; the book example of the 20-mph poor shelter feeling 5/10/15/20 mph at 30/40/50/60 with 25% then 50% damage per hour), the life span (the shelter's hit points: 1 point per three times put up, 1 per non-damaging over-wind exposure, 2 per equal-intensity precip, 4 per greater; a superior, good or adequate shelter dropping to the next category's maximum treated as that category; a poor shelter useless at half its points, 40 down to 20; the hailstorm and cracked-pole mishaps aging a shelter before its time), the rest and comfort rules (no more than 16 hours per day in active adventuring, fatigue stops not counting as rest; camp chores in three hours at most; five hours of sleep every 24 hours to avoid the risk of ill effects that may not show up right away) and TABLE 37 EFFECTS OF LACK OF SLEEP (the five bands less than 5/4/3/2/1 hours average rest per day: Dexterity Checks at +1/+2/+3/+4/+5; Strength at +1/+2/+3/+4 from the second band; Wisdom at +1/+2/+3 from the third; Constitution at +1/+2 in the bottom two; to-hit -1/-1/-2/-3; Climbing Rating -10/-20/-30 percent; Movement Rate -25/-33/-50 percent; Weight Allowance -50 and -100 x Strength), printed pp. 63-64.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 473,
  "prefix" = "wrs",
  "banner" = {
      "title" = "R473: the WSG PORTABLE SHELTER MECHANICS and REST AND COMFORT slice with TABLE 37 - the shelter kits (the poor covering loosely stitched of several pieces with wind through the seams and no anchoring gear or rope provided, what an unskilled maker ends up with; the adequate kit of at least two poles - a backbone ridgepole and a cross-brace - with tighter stitching and stakes driven through the covering edges; the good kit of at least four poles with the covering pieces stitched tightly and overlapped like shingles so no seams are exposed and reinforced edge holes for damage-free anchoring; the superior kit of at least six poles making a strong frame, a tailored covering of as few pieces as possible with reinforced seams - a true structure, the next best thing to a miner's shack), the occupancy (a small shelter one human-sized or two smaller characters plus all their gear, twice as many in close quarters; a medium two human-sized, twice as many close; a large four by design, five or six sleeping with gear stored outside, seven or eight in close quarters and no more than eight), the setup and takedown discipline (a second character reducing setup by 1 turn; a rope use proficient character halving the setup time rounded up with or without help; the 1/2/3-turn setup minimums by size; the takedown in 1 turn less than setup regardless of helpers, halved by rope use proficiency, with the 5-round/1-turn/2-turn minimums; the poor and adequate kits assuming the characters bring their own rope), the moisture rule (precip heavier than the value gets through as a storm one step lighter; a superior shelter protecting from even a downpour unless the wind is too strong or the storm separates it from its moorings), the wind rules (the greatest velocity withstood without leaking; every 10 mph above the number a 5 mph wind felt inside; above twice the number a 25% chance per 10 mph each hour of wind damage leaving the shelter useless until repaired; the book example of the 20-mph poor shelter feeling 5/10/15/20 mph at 30/40/50/60 with 25% then 50% damage per hour), the life span (the shelter's hit points: 1 point per three times put up, 1 per non-damaging over-wind exposure, 2 per equal-intensity precip, 4 per greater; a superior, good or adequate shelter dropping to the next category's maximum treated as that category; a poor shelter useless at half its points, 40 down to 20; the hailstorm and cracked-pole mishaps aging a shelter before its time), the rest and comfort rules (no more than 16 hours per day in active adventuring, fatigue stops not counting as rest; camp chores in three hours at most; five hours of sleep every 24 hours to avoid the risk of ill effects that may not show up right away) and TABLE 37 EFFECTS OF LACK OF SLEEP (the five bands less than 5/4/3/2/1 hours average rest per day: Dexterity Checks at +1/+2/+3/+4/+5; Strength at +1/+2/+3/+4 from the second band; Wisdom at +1/+2/+3 from the third; Constitution at +1/+2 in the bottom two; to-hit -1/-1/-2/-3; Climbing Rating -10/-20/-30 percent; Movement Rate -25/-33/-50 percent; Weight Allowance -50 and -100 x Strength), printed pp. 63-64.",
      "provenance" = "Ground truth two-way on the prose, three-way on the contested grid cells, no physical-page reads: the user-run Termux tesseract text of printed pp. 63-64 (p63_full.txt, p64_full.txt) vs the pdf embedded text layer (pdftotext -layout, pdf pages 64-65, p63_64_pdfy.txt). The two readers AGREE on all prose numbers: the 2/4/6 pole minimums, the occupancy counts, the 1-turn helper saving, the 1/2/3-turn setup minimums, the one-turn-less takedown with the 5-round/1-turn/2-turn minimums, the 10-mph/5-mph wind leak step, the twice-threshold 25% damage chance, the 1/3-use and 1/2/4 life span point rates, the poor 40-to-20 collapse, the 16/3/5-hour rules, the two-day trigger, the one-night negation and the 12-to-6 movement example. For the TABLE 37 GRID the tesseract TSV geometry and full text carry every cell EXCEPT the LESS-THAN-2 DEXTERITY AND STRENGTH cells, which tesseract garbles into low-confidence noise: the pdf layer reads them as Dexterity Checks at +4 and Strength Checks at +3, and a VISION READ of the uploaded page image (pg-001-2.png) SECOND-CONFIRMS the full grid including those two contested cells - the R471 vision-on-png combo as the standing contested-cell settler. The grid is also internally consistent: each ability ladder steps exactly one per band, and the less-than-5 band carries the Dexterity entry alone.",
      "sentinel" = "All 40 Table 37 cells pinned (the five bands by eight effect columns); the shelter kit mechanics, the setup and takedown discipline, the wind and moisture semantics, the life span economy, the rest and sleep rules and the book's own worked wind and movement examples are audit examples.",
    },
  "consts" = { {
      "name" = "wrsAdequateMinPoles",
      "value" = 2,
      "comment" = "the adequate shelter kit includes at least two poles: one for a backbone (ridgepole) and one for a cross-brace",
    }, {
      "name" = "wrsGoodMinPoles",
      "value" = 4,
      "comment" = "the good kit: at least four poles - a ridgepole, a cross-brace and two side poles for added strength and stability",
    }, {
      "name" = "wrsSuperiorMinPoles",
      "value" = 6,
      "comment" = "the superior kit: at least six poles, enough to actually make a simple but strong frame for the cover",
    }, {
      "name" = "wrsSmallComfort",
      "value" = 1,
      "comment" = "a small shelter comfortably holds one human-sized character (or two smaller ones) plus all their personal gear",
    }, {
      "name" = "wrsMediumComfort",
      "value" = 2,
      "comment" = "a medium shelter easily accommodates two human-sized characters, or the equivalent in smaller characters",
    }, {
      "name" = "wrsLargeDesign",
      "value" = 4,
      "comment" = "a large shelter is designed to hold four human-sized characters",
    }, {
      "name" = "wrsLargeSleepMax",
      "value" = 6,
      "comment" = "a large shelter can sleep five or six men if the group stores some of its gear outside",
    }, {
      "name" = "wrsLargeCloseMax",
      "value" = 8,
      "comment" = "a large shelter holds seven or eight men in close quarters, and no more than eight can sleep inside it",
    }, {
      "name" = "wrsSetupHelperSaving",
      "value" = 1,
      "comment" = "a second character assisting with the setup reduces the time by 1 turn",
    }, {
      "name" = "wrsSetupMinSmallTurns",
      "value" = 1,
      "comment" = "it takes at least 1 turn to set up a small shelter",
    }, {
      "name" = "wrsSetupMinMediumTurns",
      "value" = 2,
      "comment" = "a medium shelter takes at least 2 turns to set up",
    }, {
      "name" = "wrsSetupMinLargeTurns",
      "value" = 3,
      "comment" = "a large shelter takes at least 3 turns to set up",
    }, {
      "name" = "wrsTakedownSavingTurns",
      "value" = 1,
      "comment" = "taking down the shelter and re-packing it takes 1 turn less than it took to put up",
    }, {
      "name" = "wrsTakedownMinSmallRounds",
      "value" = 5,
      "comment" = "at least five rounds to dismantle and pack a small shelter",
    }, {
      "name" = "wrsTakedownMinMediumTurns",
      "value" = 1,
      "comment" = "at least 1 turn to dismantle and pack a medium shelter",
    }, {
      "name" = "wrsTakedownMinLargeTurns",
      "value" = 2,
      "comment" = "at least 2 turns to dismantle and pack a large shelter",
    }, {
      "name" = "wrsWindStepMph",
      "value" = 10,
      "comment" = "for every 10 mph of actual wind velocity greater than the indicated number",
    }, {
      "name" = "wrsWindLeakMph",
      "value" = 5,
      "comment" = "those inside the tent feel a wind of 5 mph for each 10 mph step above the rating",
    }, {
      "name" = "wrsWindDamageThresholdMult",
      "value" = 2,
      "comment" = "the wind damage chance applies if the velocity exceeds twice the indicated number",
    }, {
      "name" = "wrsWindDamagePctPerStep",
      "value" = 25,
      "comment" = "a 25% chance for each 10 mph of additional velocity, checked each hour, that the wind damages the shelter",
    }, {
      "name" = "wrsWindExPoorRes",
      "value" = 20,
      "comment" = "the book wind example: a poor shelter provides complete protection up to 20 mph",
    }, {
      "name" = "wrsWindEx30Leak",
      "value" = 5,
      "comment" = "the book example: at 30 mph those inside feel a breeze of 5 mph",
    }, {
      "name" = "wrsWindEx40Leak",
      "value" = 10,
      "comment" = "the book example: at 40 mph the breeze inside is 10 mph",
    }, {
      "name" = "wrsWindEx50Leak",
      "value" = 15,
      "comment" = "the book example: at 50 mph the breeze inside is 15 mph",
    }, {
      "name" = "wrsWindEx60Leak",
      "value" = 20,
      "comment" = "the book example: at 60 mph the breeze inside has reached a hefty 20 mph",
    }, {
      "name" = "wrsWindEx50DamagePct",
      "value" = 25,
      "comment" = "the book example: at 50 mph a 25% chance per hour of wind damage",
    }, {
      "name" = "wrsWindEx60DamagePct",
      "value" = 50,
      "comment" = "the book example: at 60 mph a 50% chance per hour of wind damage",
    }, {
      "name" = "wrsLifespanSetupsPerPoint",
      "value" = 3,
      "comment" = "1 life span point deducted for each three times the shelter is put up",
    }, {
      "name" = "wrsLifespanWindPoints",
      "value" = 1,
      "comment" = "1 point for each exposure to wind speeds above its wind resistance that does no actual damage",
    }, {
      "name" = "wrsLifespanEqualPrecipPoints",
      "value" = 2,
      "comment" = "2 points for each exposure to precipitation equal in intensity to its moisture resistance value",
    }, {
      "name" = "wrsLifespanGreaterPrecipPoints",
      "value" = 4,
      "comment" = "4 points for each exposure to precipitation greater in intensity than its moisture resistance value",
    }, {
      "name" = "wrsPoorLifespanMax",
      "value" = 40,
      "comment" = "a poor shelter starts with 40 life span points",
    }, {
      "name" = "wrsPoorUselessAt",
      "value" = 20,
      "comment" = "a poor shelter losing half its maximum points (from 40 to 20) is useless until repaired",
    }, {
      "name" = "wrsMaxActiveHours",
      "value" = 16,
      "comment" = "a character should spend no more than 16 hours per day in active adventuring pursuits",
    }, {
      "name" = "wrsCampChoreHours",
      "value" = 3,
      "comment" = "setting up a shelter, hunting and foraging, and cooking the nighttime meal should all be done in three hours at most",
    }, {
      "name" = "wrsSleepHoursNeeded",
      "value" = 5,
      "comment" = "a character needs five hours of sleep every 24 hours to avoid the risk of ill effects from lack of rest",
    }, {
      "name" = "wrsTriggerDays",
      "value" = 2,
      "comment" = "the lack-of-sleep effects do not set in until a character has gone two days without at least five hours of sleep during one of them",
    }, {
      "name" = "wrsExMoveRate",
      "value" = 12,
      "comment" = "the book movement example: a character with a normal movement rate of 12",
    }, {
      "name" = "wrsExHalfDayMiles",
      "value" = 6,
      "comment" = "the book movement example: operating with less than 1 hour of sleep he can travel only 6 miles per half-day on foot",
    }, {
      "name" = "wrsSleepBands",
      "value" = 5,
      "comment" = "the Table 37 average-rest bands: less than 5, 4, 3, 2 and 1 hours",
    }, {
      "name" = "wrsRowCount",
      "value" = 5,
      "comment" = "the Table 37 row count",
    } },
  "bools" = { {
      "name" = "wrsPoorKitLooseStitching",
      "value" = true,
      "comment" = "the poor shelter \"single piece\" covering is actually several pieces loosely stitched with rawhide or cord neither particularly strong nor durable: wind easily finds its way in through the seams, and the covering does not completely keep out rain or snow because of its loose construction",
    }, {
      "name" = "wrsPoorKitBringYourOwn",
      "value" = true,
      "comment" = "the poor kit provides no special anchoring equipment and no rope: the edges must be anchored with rocks or other weights at hand or handmade stakes whittled from branches, the characters provide their own rope, and an unskilled character manufacturing a portable shelter ends up with this quality",
    }, {
      "name" = "wrsAdequateKitTighter",
      "value" = true,
      "comment" = "the adequate covering is made of multiple sections just as a poor one, but the edges are more closely matched and the stitching tighter and stronger: it does not let in wind or precipitation as easily, and its wooden or metal stakes are driven through the edges into the ground",
    }, {
      "name" = "wrsGoodKitShingled",
      "value" = true,
      "comment" = "the good covering pieces are not only stitched tightly together but overlapped like shingles so no seams are directly exposed on the outer surface, and the edges contain reinforced holes through which a stake can be driven or a rope strung to anchor without damaging the material",
    }, {
      "name" = "wrsSuperiorKitStructure",
      "value" = true,
      "comment" = "the superior covering is extremely well waterproofed, made of as few separate pieces as possible with joined seams reinforced by another thickness of material: a true structure keeping out all but the strongest wind and heaviest precipitation, the next best thing to finding a miner's shack",
    }, {
      "name" = "wrsSmallCloseQuarters",
      "value" = true,
      "comment" = "the small shelter can be used to shelter up to twice as many occupants in close quarters",
    }, {
      "name" = "wrsMediumCloseQuarters",
      "value" = true,
      "comment" = "the medium shelter holds up to twice as many in close quarters",
    }, {
      "name" = "wrsLargeCloseQuartersOnly8",
      "value" = true,
      "comment" = "no more than eight can sleep inside a large shelter without some of the occupants being literally on top of others",
    }, {
      "name" = "wrsSetupAssumesRope",
      "value" = true,
      "comment" = "the poor and adequate setup times assume the characters have rope and, for a poor shelter, some objects with which to anchor the cover",
    }, {
      "name" = "wrsRopeUseHalvesSetup",
      "value" = true,
      "comment" = "a character with proficiency in rope use sets up the shelter, with or without help, in half the time (rounded up) indicated by the die roll",
    }, {
      "name" = "wrsTakedownNoHelperBonus",
      "value" = true,
      "comment" = "the takedown time is 1 turn less than the setup time regardless of how many characters assist",
    }, {
      "name" = "wrsRopeUseHalvesTakedown",
      "value" = true,
      "comment" = "a character with proficiency in rope use can dismantle and properly pack a shelter in half the time it takes a nonproficient character",
    }, {
      "name" = "wrsMoistureOneStepLighter",
      "value" = true,
      "comment" = "precipitation heavier than the moisture resistance value gets through the shelter and falls on the occupants as though they were in a storm one step lighter in intensity (a poor shelter douses its occupants in a moderate storm as if they were in the open during a light one)",
    }, {
      "name" = "wrsSuperiorDownpourCaveat",
      "value" = true,
      "comment" = "a superior shelter protects those inside from even a downpour, as long as the wind is not too strong and the force of the storm does not separate the shelter from its moorings",
    }, {
      "name" = "wrsWindLeakRule",
      "value" = true,
      "comment" = "the wind resistance number is the greatest wind velocity the shelter withstands without leaking, and the effective temperature inside changes with the leaked breeze",
    }, {
      "name" = "wrsWindDamageUseless",
      "value" = true,
      "comment" = "a wind-damaged shelter is useless until it is repaired",
    }, {
      "name" = "wrsLifespanAsHitPoints",
      "value" = true,
      "comment" = "life span may be thought of as the shelter's hit points: a new or freshly repaired shelter has the indicated number of life span points",
    }, {
      "name" = "wrsCategoryDegradation",
      "value" = true,
      "comment" = "when a superior, good or adequate shelter loses enough points to bring it down to the maximum value of the next lower category, it is treated as a shelter of that category until it deteriorates completely or is repaired",
    }, {
      "name" = "wrsPoorHalfUseless",
      "value" = true,
      "comment" = "repair costs and availability are in the province of the DM, but hauling a dilapidated poor shelter into town to be fixed would cost more effort and time than it is worth: cut up the cover and make it into sacks or saddle blankets",
    }, {
      "name" = "wrsLifespanHazards",
      "value" = true,
      "comment" = "the life span does not account for mishaps that age a shelter early: a hailstorm may at the DM discretion punch holes or weaken the seams, a tent pole cracked flailing on a wild bear will not hold the cover in a stiff wind, but barring such occurrences most shelters serve well for an adventure or two or longer",
    }, {
      "name" = "wrsActiveTimeCap",
      "value" = true,
      "comment" = "the 16-hour active time includes rest stops taken to avoid fatigue, which do not count as actual rest for these rules; the remainder of the day is set aside for making camp, eating and sleeping",
    }, {
      "name" = "wrsSleepRiskHidden",
      "value" = true,
      "comment" = "an improperly rested character's ill effects may not show up right away, might not manifest themselves at all if he is lucky, or might come back to haunt him at a very inopportune time",
    }, {
      "name" = "wrsTwoDayTrigger",
      "value" = true,
      "comment" = "a character can stay up all night and function normally throughout the next day, but if he does not get at least five hours of sleep on the following night then the effects begin at sunrise or when he awakens",
    }, {
      "name" = "wrsDayByDayCalc",
      "value" = true,
      "comment" = "average rest per day is calculated on a day-by-day basis whenever a character goes two or more consecutive days without getting at least five hours of sleep during one of those days",
    }, {
      "name" = "wrsOneNightNegation",
      "value" = true,
      "comment" = "as soon as he gets five hours of sleep in a single day, any and all effects are negated: the character is replenished by one good night's sleep even after several deprived days in a row",
    }, {
      "name" = "wrsCheckModifierOnRoll",
      "value" = true,
      "comment" = "the table modifiers are applied to the die roll whenever an Ability Check or a Proficiency Check related to the indicated ability is called for",
    }, {
      "name" = "wrsMoveReductionAfterAdjustments",
      "value" = true,
      "comment" = "the movement rate entries reduce the character's normal large-scale movement rate, taken after all other adjustments for terrain and encumbrance are accounted for",
    }, {
      "name" = "wrsCombatMoveExempt",
      "value" = true,
      "comment" = "the movement penalty does not apply in combat situations or other feet-per-round movement: ambushed while travelling 6 miles per half-day, the character still moves at his full rate while the combat episode is resolved",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "wrsSleepEffects",
      "tag" = "37",
      "count" = "wrsRowCount",
      "cols" = { "wrsDexCheck", "wrsStrCheck", "wrsWisCheck", "wrsConCheck", "wrsToHit", "wrsClimbPct", "wrsMovePct", "wrsWtMult" },
      "col_default" = 0,
      "col_comments" = { "the Table 37 Dexterity Check modifier on the die roll", "the Table 37 Strength Check modifier on the die roll", "the Table 37 Wisdom Check modifier on the die roll", "the Table 37 Constitution Check modifier on the die roll", "the Table 37 to-hit penalty", "the Table 37 Climbing Rating reduction percent", "the Table 37 Movement Rate reduction percent", "the Table 37 Weight Allowance penalty, a multiple of the character's Strength" },
      "row_comments" = { "the less-than-5-hours row", "the less-than-4-hours row", "the less-than-3-hours row", "the less-than-2-hours row", "the less-than-1-hour row" },
      "data" = { { 1, 0, 0, 0, 0, 0, 0, 0 }, { 2, 1, 0, 0, -1, 0, 0, 0 }, { 3, 2, 1, 0, -1, -10, -25, 0 }, { 4, 3, 2, 1, -2, -20, -33, 50 }, { 5, 4, 3, 2, -3, -30, -50, 100 } },
      "audit_comment" = "Table 37: effects of lack of sleep, the five average-rest bands by eight effect columns (the ability check ladders, the to-hit penalties, the climbing and movement reductions, the weight allowance multiples), printed p. 64",
      "sentinel" = 999,
      "sentinel_census" = { 0, 0, 0, 0, 0, 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "note" = "the pole kits: 2 adequate, 4 good, 6 superior, each strictly more than the last",
      "expr" = "m['wrsAdequateMinPoles']() != 2 or m['wrsGoodMinPoles']() != 4 or m['wrsSuperiorMinPoles']() != 6 or m['wrsAdequateMinPoles']() >= m['wrsGoodMinPoles']() or m['wrsGoodMinPoles']() >= m['wrsSuperiorMinPoles']()",
    }, {
      "note" = "the occupancy ladder: 1 small, 2 medium, 4 large by design with the 6 sleep and 8 close-quarters caps",
      "expr" = "m['wrsSmallComfort']() != 1 or m['wrsMediumComfort']() != 2 or m['wrsLargeDesign']() != 4 or m['wrsLargeSleepMax']() != 6 or m['wrsLargeCloseMax']() != 8 or m['wrsLargeDesign']() >= m['wrsLargeSleepMax']() or m['wrsLargeSleepMax']() >= m['wrsLargeCloseMax']()",
    }, {
      "note" = "the setup minimums: 1/2/3 turns by size and the 1-turn helper saving",
      "expr" = "m['wrsSetupMinSmallTurns']() != 1 or m['wrsSetupMinMediumTurns']() != 2 or m['wrsSetupMinLargeTurns']() != 3 or m['wrsSetupHelperSaving']() != 1 or m['wrsSetupMinSmallTurns']() >= m['wrsSetupMinMediumTurns']() or m['wrsSetupMinMediumTurns']() >= m['wrsSetupMinLargeTurns']()",
    }, {
      "note" = "the takedown: 1 turn less than setup with the 5-round small and 1/2-turn medium/large minimums",
      "expr" = "m['wrsTakedownSavingTurns']() != 1 or m['wrsTakedownMinSmallRounds']() != 5 or m['wrsTakedownMinMediumTurns']() != 1 or m['wrsTakedownMinLargeTurns']() != 2 or m['wrsTakedownMinMediumTurns']() >= m['wrsTakedownMinLargeTurns']()",
    }, {
      "note" = "the wind machinery: the 10-mph step, the 5-mph leak, the twice-threshold and the 25% damage chance",
      "expr" = "m['wrsWindStepMph']() != 10 or m['wrsWindLeakMph']() != 5 or m['wrsWindDamageThresholdMult']() != 2 or m['wrsWindDamagePctPerStep']() != 25",
    }, {
      "note" = "the book wind example: the 20-mph poor shelter leaks 5/10/15/20 mph at 30/40/50/60 mph, damage 25% then 50%",
      "expr" = "m['wrsWindExPoorRes']() != 20 or m['wrsWindEx30Leak']() != 5 or m['wrsWindEx40Leak']() != 10 or m['wrsWindEx50Leak']() != 15 or m['wrsWindEx60Leak']() != 20 or m['wrsWindEx50DamagePct']() != 25 or m['wrsWindEx60DamagePct']() != 50 or m['wrsWindEx30Leak']() >= m['wrsWindEx40Leak']() or m['wrsWindEx40Leak']() >= m['wrsWindEx50Leak']() or m['wrsWindEx50Leak']() >= m['wrsWindEx60Leak']() or m['wrsWindEx50DamagePct']() >= m['wrsWindEx60DamagePct']()",
    }, {
      "note" = "the life span point rates: 1 per 3 setups, 1 per non-damaging over-wind, 2 equal precip, 4 greater",
      "expr" = "m['wrsLifespanSetupsPerPoint']() != 3 or m['wrsLifespanWindPoints']() != 1 or m['wrsLifespanEqualPrecipPoints']() != 2 or m['wrsLifespanGreaterPrecipPoints']() != 4 or m['wrsLifespanWindPoints']() >= m['wrsLifespanEqualPrecipPoints']() or m['wrsLifespanEqualPrecipPoints']() >= m['wrsLifespanGreaterPrecipPoints']()",
    }, {
      "note" = "the poor shelter collapse: half of 40 is 20",
      "expr" = "m['wrsPoorLifespanMax']() != 40 or m['wrsPoorUselessAt']() != 20 or m['wrsPoorUselessAt']() >= m['wrsPoorLifespanMax']()",
    }, {
      "note" = "the rest day: 16 hours active, 3 hours of chores, 5 hours of sleep",
      "expr" = "m['wrsMaxActiveHours']() != 16 or m['wrsCampChoreHours']() != 3 or m['wrsSleepHoursNeeded']() != 5",
    }, {
      "note" = "the two-day trigger",
      "expr" = "m['wrsTriggerDays']() != 2",
    }, {
      "note" = "the book movement example: 12 down to 6 miles per half-day",
      "expr" = "m['wrsExMoveRate']() != 12 or m['wrsExHalfDayMiles']() != 6 or m['wrsExHalfDayMiles']() >= m['wrsExMoveRate']()",
    }, {
      "note" = "the kit mechanics: the poor loose kit, the adequate tight one, the good shingles, the superior true structure",
      "expr" = "m['wrsPoorKitLooseStitching']() != 1 or m['wrsPoorKitBringYourOwn']() != 1 or m['wrsAdequateKitTighter']() != 1 or m['wrsGoodKitShingled']() != 1 or m['wrsSuperiorKitStructure']() != 1",
    }, {
      "note" = "the occupancy rulings: small and medium close quarters, the large eight cap",
      "expr" = "m['wrsSmallCloseQuarters']() != 1 or m['wrsMediumCloseQuarters']() != 1 or m['wrsLargeCloseQuartersOnly8']() != 1",
    }, {
      "note" = "the setup and takedown rope rules",
      "expr" = "m['wrsSetupAssumesRope']() != 1 or m['wrsRopeUseHalvesSetup']() != 1 or m['wrsTakedownNoHelperBonus']() != 1 or m['wrsRopeUseHalvesTakedown']() != 1",
    }, {
      "note" = "the moisture and wind rulings",
      "expr" = "m['wrsMoistureOneStepLighter']() != 1 or m['wrsSuperiorDownpourCaveat']() != 1 or m['wrsWindLeakRule']() != 1 or m['wrsWindDamageUseless']() != 1",
    }, {
      "note" = "the life span rulings: hit points, degradation, the poor collapse, the mishap caveats",
      "expr" = "m['wrsLifespanAsHitPoints']() != 1 or m['wrsCategoryDegradation']() != 1 or m['wrsPoorHalfUseless']() != 1 or m['wrsLifespanHazards']() != 1",
    }, {
      "note" = "the rest and sleep discipline: the active-time definition, the hidden risk, the day-by-day calc and the negation",
      "expr" = "m['wrsActiveTimeCap']() != 1 or m['wrsSleepRiskHidden']() != 1 or m['wrsDayByDayCalc']() != 1 or m['wrsOneNightNegation']() != 1",
    }, {
      "note" = "the check and movement semantics with the combat exemption",
      "expr" = "m['wrsCheckModifierOnRoll']() != 1 or m['wrsMoveReductionAfterAdjustments']() != 1 or m['wrsCombatMoveExempt']() != 1",
    } },
  "audit" = {
      "label" = "R473 WSG sleep and shelter pin audit",
      "comment" = "The Table 37 grid (the five average-rest bands by eight effect columns: the Dexterity, Strength, Wisdom and Constitution check ladders, the to-hit penalties, the Climbing and Movement reductions, the Weight Allowance multiples), the shelter kit descriptions, the occupancy rulings, the setup and takedown discipline, the moisture and wind resistance semantics, the life span point economy with the category degradation, the 16-hour active day with the 5-hour sleep requirement, the two-day trigger with the one-night negation and the movement rate semantics - every const, bool and table cell verified against the model.",
    },
}
