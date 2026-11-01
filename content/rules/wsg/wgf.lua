-- wgf: promoted from tools/spec_r474.json (the R474: the WSG GOOD SLEEP VS BAD SLEEP and FIRE slice with TABLE 38 - the rest-quality penalty ladder (not prone or relaxed 1; bare ground 1, waived for a plate wearer; personal temperature below 0 one hour and above 90 two hours; wind of 20 mph or greater with no shelter 2, likewise waived; light or moderate precipitation with no shelter 3, likewise waived; any metal armor except plate 3; any plate armor 4) with the DM-summed reduction, the no-rest threshold when the total penalty exceeds the time spent trying to sleep, the extreme-weather bar (no sleep in a lightning storm, a hailstorm or a sandstorm unless inside a shelter, and even then the commotion may keep him awake), the longer-sleep compensation (a plate wearer five-hour night buys one hour of good rest, nine hours refresh like five), the sleep-in-armor prudence with the one-night-in-two rule, the armor donning discipline (9 minus AC rounds, plus 2 for any plate, plus 5 more unaided for field or full plate: leather 1, banded 5, full plate 11 helped or 16 solo, doffing in half the time with 8 rounds to shed full plate alone) and the fire function (cooking incidental, warmth primary, three sizes) with Table 38 (fuel 6/12/18 turns for an eight-hour burn, start 2d20 plus 0/5/10, refuel 3/6/9, wind resistance 20/30/40, capacity 6/10/15, visibility 240/360/540, and the warmth-at-distance ladder by size and range), printed p. 65.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 474,
  "prefix" = "wgf",
  "banner" = {
      "title" = "R474: the WSG GOOD SLEEP VS BAD SLEEP and FIRE slice with TABLE 38 - the rest-quality penalty ladder (not prone or relaxed 1; bare ground 1, waived for a plate wearer; personal temperature below 0 one hour and above 90 two hours; wind of 20 mph or greater with no shelter 2, likewise waived; light or moderate precipitation with no shelter 3, likewise waived; any metal armor except plate 3; any plate armor 4) with the DM-summed reduction, the no-rest threshold when the total penalty exceeds the time spent trying to sleep, the extreme-weather bar (no sleep in a lightning storm, a hailstorm or a sandstorm unless inside a shelter, and even then the commotion may keep him awake), the longer-sleep compensation (a plate wearer five-hour night buys one hour of good rest, nine hours refresh like five), the sleep-in-armor prudence with the one-night-in-two rule, the armor donning discipline (9 minus AC rounds, plus 2 for any plate, plus 5 more unaided for field or full plate: leather 1, banded 5, full plate 11 helped or 16 solo, doffing in half the time with 8 rounds to shed full plate alone) and the fire function (cooking incidental, warmth primary, three sizes) with Table 38 (fuel 6/12/18 turns for an eight-hour burn, start 2d20 plus 0/5/10, refuel 3/6/9, wind resistance 20/30/40, capacity 6/10/15, visibility 240/360/540, and the warmth-at-distance ladder by size and range), printed p. 65.",
      "provenance" = "Ground truth two-way on the prose and the Table 38 top grid, no physical-page reads: the user-run Termux tesseract text of printed p. 65 (p65_full.txt, p65_tsv.tsv) vs the pdf embedded text layer (pdftotext -layout, pdf page 66, p65_pdfy.txt). The two readers AGREE on all prose numbers: the eight penalty values (tesseract garbles only the minus signs on four of the eight lines, never the digits), the DM-summed reduction and the no-rest threshold, the three storm types, the 5/1 and 9/5 plate-sleep figures, the one-night-in-two rule, the 9-minus-AC donning base with the 2 and 5 round adds, the 1/5/11/16 donning figures with the half-time doffing at 8 rounds, the cooking-incidental and warmth-primary prose, and the Table 38 top grid (fuel 6/12/18, start 2d20 +0/+5/+10, refuel 3/6/9, res 20/30/40, cap 6/10/15, vis 240/360/540). For the WARMTH-AT-DISTANCE grid tesseract garbles four cells into low-confidence noise: the Small row at 50 and 60 yards (reading 00 and 10) and the Large row at 20 and 60 yards (reading 4 and O). The pdf layer reads them as 0, 0, 40 and 0, and the TSV WORD-BOX GEOMETRY (the R467 workflow) settles them: the Small at-60 box is 20 pixels wide like every single-digit cell (a true 10 is 39 wide), the Large at-20 box is 40 pixels wide exactly like every two-digit 40 cell (a lone 4 is 19 wide), and the Large at-60 box is a single glyph. The grid is also internally consistent: every row decays monotonically with distance, and at every shared distance a larger fire warms at least as much as a smaller one. NOTE: the standing vision-on-png contested-cell settler was tried twice on this page and failed both times - each vision read contradicted the two agreeing text layers on uncontested cells (reading the refuel column as the start dice and inventing dashes mid-row), so the TSV geometry plus monotonicity is the settler of record this round.",
      "sentinel" = "All 27 warmth-grid cells pinned (the three sizes by nine distances, with 999 marking the three printed dashes as no warmth at that distance: a medium fire provides none at 1, a large fire none at 1 or 3); the 24 top-grid cells, the eight penalties, the armor timing figures and the book own plate-sleep and donning examples are audit examples.",
    },
  "consts" = { {
      "name" = "wgfPenNotProne",
      "value" = 1,
      "comment" = "the rest-quality penalty for a character not prone or in a relaxed position: 1 hour of good rest lost",
    }, {
      "name" = "wgfPenBareGround",
      "value" = 1,
      "comment" = "the penalty for lying on bare ground with no bedding or padding: 1 hour lost (waived for a plate-armor wearer)",
    }, {
      "name" = "wgfPenTempBelow0",
      "value" = 1,
      "comment" = "the penalty for personal temperature below 0 degrees: 1 hour lost",
    }, {
      "name" = "wgfPenTempAbove90",
      "value" = 2,
      "comment" = "the penalty for personal temperature above 90 degrees: 2 hours lost",
    }, {
      "name" = "wgfPenWindNoShelter",
      "value" = 2,
      "comment" = "the penalty for wind of 20 mph or greater with no shelter: 2 hours lost (waived for a plate-armor wearer)",
    }, {
      "name" = "wgfPenPrecipNoShelter",
      "value" = 3,
      "comment" = "the penalty for light or moderate precipitation with no shelter: 3 hours lost (waived for a plate-armor wearer)",
    }, {
      "name" = "wgfPenMetalArmor",
      "value" = 3,
      "comment" = "the penalty for wearing any metal armor except plate: 3 hours lost",
    }, {
      "name" = "wgfPenPlateArmor",
      "value" = 4,
      "comment" = "the penalty for wearing any kind of plate armor: 4 hours lost",
    }, {
      "name" = "wgfPlateTypicalNight",
      "value" = 5,
      "comment" = "the plate-armor sleeper bedding down for a typical night of five hours",
    }, {
      "name" = "wgfPlateNightGoodRest",
      "value" = 1,
      "comment" = "a five-hour night in plate armor yields the equivalent of one hour of actual rest",
    }, {
      "name" = "wgfPlateLongSleep",
      "value" = 9,
      "comment" = "sleeping nine hours in plate armor instead",
    }, {
      "name" = "wgfPlateLongRefresh",
      "value" = 5,
      "comment" = "nine hours in plate refreshes like five hours with the armor off",
    }, {
      "name" = "wgfDonBase",
      "value" = 9,
      "comment" = "the armor donning base: subtract the armor class from 9 to get the rounds to put it on",
    }, {
      "name" = "wgfPlateAddRounds",
      "value" = 2,
      "comment" = "any plate armor (bronze plate mail, plate mail, field plate or full plate) adds 2 rounds to the calculated figure",
    }, {
      "name" = "wgfUnaidedAddRounds",
      "value" = 5,
      "comment" = "field plate or full plate donned without help adds an extra 5 rounds",
    }, {
      "name" = "wgfLeatherAC",
      "value" = 8,
      "comment" = "leather armor is AC 8",
    }, {
      "name" = "wgfLeatherDonRounds",
      "value" = 1,
      "comment" = "leather armor (AC 8) can be donned in one round",
    }, {
      "name" = "wgfBandedAC",
      "value" = 4,
      "comment" = "banded mail is AC 4",
    }, {
      "name" = "wgfBandedDonRounds",
      "value" = 5,
      "comment" = "banded mail (AC 4) requires five rounds",
    }, {
      "name" = "wgfFullPlateAC",
      "value" = 0,
      "comment" = "full plate armor is AC 0",
    }, {
      "name" = "wgfFullPlateHelpedRounds",
      "value" = 11,
      "comment" = "full plate armor (AC 0) needs 11 rounds with the help of a comrade",
    }, {
      "name" = "wgfFullPlateSoloRounds",
      "value" = 16,
      "comment" = "full plate armor needs 16 rounds singlehandedly",
    }, {
      "name" = "wgfFullPlateSoloDoffRounds",
      "value" = 8,
      "comment" = "taking off a suit of full plate armor without help takes 8 rounds (half of 16)",
    }, {
      "name" = "wgfFireSizes",
      "value" = 3,
      "comment" = "a campfire can be built in one of three sizes",
    }, {
      "name" = "wgfBurnHours",
      "value" = 8,
      "comment" = "the fuel values gather enough material to keep a fire of that size burning for eight hours",
    } },
  "bools" = { {
      "name" = "wgfQualityNotNight",
      "value" = true,
      "comment" = "a good night rest speaks to the quality of the rest, not the night",
    }, {
      "name" = "wgfComfortRequired",
      "value" = true,
      "comment" = "to fully benefit from his sleeping time a character must be able to rest in comfort, which is not always easy in the wilderness",
    }, {
      "name" = "wgfPenaltiesSummed",
      "value" = true,
      "comment" = "the Dungeon Master adds up all of the penalties that apply and reduces the hours of sleep by the indicated amount",
    }, {
      "name" = "wgfNoRestWhenExceeded",
      "value" = true,
      "comment" = "if the total penalty exceeds the time the character spends trying to sleep, the resting did him no good at all",
    }, {
      "name" = "wgfStarPenaltiesSkipPlate",
      "value" = true,
      "comment" = "the starred penalties (bare ground, wind and precipitation) do not apply to a character wearing plate armor",
    }, {
      "name" = "wgfExtremeWeatherNoSleep",
      "value" = true,
      "comment" = "it is impossible to sleep in extreme weather such as a lightning storm, a hailstorm or a sandstorm unless the character is inside a shelter",
    }, {
      "name" = "wgfStormCommotionCaveat",
      "value" = true,
      "comment" = "even inside a shelter the commotion caused by the storm may keep him awake",
    }, {
      "name" = "wgfDmMayExpandPenalties",
      "value" = true,
      "comment" = "the Dungeon Master may expand the penalty list to account for other circumstances where good-quality rest is difficult or impossible",
    }, {
      "name" = "wgfLongerSleepCompensates",
      "value" = true,
      "comment" = "one way to compensate for bad rest is to spend a longer time sleeping",
    }, {
      "name" = "wgfArmorSleepPrudent",
      "value" = true,
      "comment" = "if characters might be set upon during the night, sleeping in full armor is probably more prudent than taking it off",
    }, {
      "name" = "wgfOneNightInTwoSuffices",
      "value" = true,
      "comment" = "because the lack-of-sleep penalties do not go into effect until after the second night of deprivation, enough sleep on one night out of every two is sufficient",
    }, {
      "name" = "wgfDonIsNineMinusAC",
      "value" = true,
      "comment" = "the donning time in rounds is 9 minus the armor class of the armor being worn",
    }, {
      "name" = "wgfPlateAddTwoRounds",
      "value" = true,
      "comment" = "any plate armor adds 2 rounds to the calculated donning figure",
    }, {
      "name" = "wgfUnaidedAddFiveRounds",
      "value" = true,
      "comment" = "field plate or full plate donned without help takes an extra 5 rounds",
    }, {
      "name" = "wgfDoffHalfTime",
      "value" = true,
      "comment" = "taking off armor can be done in half the time required to put it on",
    }, {
      "name" = "wgfLeatherDoffHalfRound",
      "value" = true,
      "comment" = "a character gets out of his leather gear in one half of one round",
    }, {
      "name" = "wgfFireNotIntegral",
      "value" = true,
      "comment" = "a campfire is not an integral part of a campsite, though characters usually want a small fire when they stop for the night",
    }, {
      "name" = "wgfCookingIncidental",
      "value" = true,
      "comment" = "the cooking function of a fire is incidental for these rules: food from hunting or foraging is just as edible raw",
    }, {
      "name" = "wgfPlantsPoisonousRaw",
      "value" = true,
      "comment" = "some plants are poisonous unless they are cooked, so characters who do not habitually cook may regret their indiscretion",
    }, {
      "name" = "wgfWarmthPrimary",
      "value" = true,
      "comment" = "the primary function of a campfire is to provide warmth",
    }, {
      "name" = "wgfWarmthLifeOrDeath",
      "value" = true,
      "comment" = "the warmth of a campfire can sometimes make the difference between life and death",
    }, {
      "name" = "wgfFuelGatherTurns",
      "value" = true,
      "comment" = "the fuel value is how many turns a single character needs to gather enough wood or other combustible material for an eight-hour burn",
    }, {
      "name" = "wgfAssumesFirewood",
      "value" = true,
      "comment" = "the fuel values assume that firewood is available in the environment",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "wgfCampfireSpecs",
      "tag" = "38",
      "count" = "wgfFireSizes",
      "cols" = { "wgfFuel", "wgfStartDie", "wgfStartCount", "wgfStartMod", "wgfRefuel", "wgfWindRes", "wgfCapacity", "wgfVisibility" },
      "col_default" = 0,
      "col_comments" = { "the Table 38 fuel: turns for one character to gather material for an eight-hour burn", "the Table 38 start die", "the Table 38 start die count", "the Table 38 start modifier", "the Table 38 refuel interval", "the Table 38 wind resistance value", "the Table 38 capacity value", "the Table 38 visibility value" },
      "row_comments" = { "the small-fire row", "the medium-fire row", "the large-fire row" },
      "data" = { { 6, 20, 2, 0, 3, 20, 6, 240 }, { 12, 20, 2, 5, 6, 30, 10, 360 }, { 18, 20, 2, 10, 9, 40, 15, 540 } },
      "audit_comment" = "Table 38: campfire characteristics, the three fire sizes by fuel, start dice, refuel, wind resistance, capacity and visibility, printed p. 65",
      "sentinel" = 999,
      "sentinel_census" = { 0, 0, 0, 0, 0, 0, 0, 0 },
    }, {
      "name" = "wgfWarmth",
      "tag" = "38w",
      "count" = "wgfFireSizes",
      "cols" = { "wgfWarmAt1", "wgfWarmAt3", "wgfWarmAt5", "wgfWarmAt10", "wgfWarmAt20", "wgfWarmAt30", "wgfWarmAt40", "wgfWarmAt50", "wgfWarmAt60" },
      "col_default" = 0,
      "col_comments" = { "the Table 38 warmth at distance 1 (999 = the printed dash: no warmth at this distance)", "the Table 38 warmth at distance 3 (999 = the printed dash: no warmth at this distance)", "the Table 38 warmth at distance 5", "the Table 38 warmth at distance 10", "the Table 38 warmth at distance 20", "the Table 38 warmth at distance 30", "the Table 38 warmth at distance 40", "the Table 38 warmth at distance 50", "the Table 38 warmth at distance 60" },
      "row_comments" = { "the small-fire row", "the medium-fire row", "the large-fire row" },
      "data" = { { 80, 60, 40, 30, 20, 10, 0, 0, 0 }, { 999, 80, 60, 40, 30, 20, 10, 0, 0 }, { 999, 999, 80, 60, 40, 30, 20, 10, 0 } },
      "audit_comment" = "Table 38: warmth provided at given distance, the three fire sizes by nine distances with the dash cells as the 999 no-warmth sentinel, printed p. 65",
      "sentinel" = 999,
      "sentinel_census" = { 2, 1, 0, 0, 0, 0, 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "note" = "the rest-quality penalty ladder: 1/1/1/2/2/3/3/4 hours by the eight conditions",
      "expr" = "m['wgfPenNotProne']() != 1 or m['wgfPenBareGround']() != 1 or m['wgfPenTempBelow0']() != 1 or m['wgfPenTempAbove90']() != 2 or m['wgfPenWindNoShelter']() != 2 or m['wgfPenPrecipNoShelter']() != 3 or m['wgfPenMetalArmor']() != 3 or m['wgfPenPlateArmor']() != 4",
    }, {
      "note" = "the penalties never grow smaller down the list and plate armor is the worst of them",
      "expr" = "m['wgfPenNotProne']() > m['wgfPenBareGround']() or m['wgfPenBareGround']() > m['wgfPenTempBelow0']() or m['wgfPenTempBelow0']() > m['wgfPenTempAbove90']() or m['wgfPenTempAbove90']() > m['wgfPenWindNoShelter']() or m['wgfPenWindNoShelter']() > m['wgfPenPrecipNoShelter']() or m['wgfPenPrecipNoShelter']() > m['wgfPenMetalArmor']() or m['wgfPenMetalArmor']() > m['wgfPenPlateArmor']()",
    }, {
      "note" = "the plate-armor sleeper: a five-hour night buys one hour of good rest, nine hours refresh like five",
      "expr" = "m['wgfPlateTypicalNight']() != 5 or m['wgfPlateNightGoodRest']() != 1 or m['wgfPlateLongSleep']() != 9 or m['wgfPlateLongRefresh']() != 5",
    }, {
      "note" = "the donning ladder: leather in 1 round, banded in 5, full plate in 11 helped or 16 solo, 8 to shed solo",
      "expr" = "m['wgfLeatherAC']() != 8 or m['wgfLeatherDonRounds']() != 1 or m['wgfBandedAC']() != 4 or m['wgfBandedDonRounds']() != 5 or m['wgfFullPlateAC']() != 0 or m['wgfFullPlateHelpedRounds']() != 11 or m['wgfFullPlateSoloRounds']() != 16 or m['wgfFullPlateSoloDoffRounds']() != 8",
    }, {
      "note" = "the helped full plate figure sits between the calculated base and the solo figure, and solo is the worst",
      "expr" = "m['wgfFullPlateHelpedRounds']() >= m['wgfFullPlateSoloRounds']() or m['wgfFullPlateSoloDoffRounds']() >= m['wgfFullPlateSoloRounds']()",
    }, {
      "note" = "the fuel ladder: 6/12/18 turns, each size strictly more than the last",
      "expr" = "m['wgfFuel'](0) != 6 or m['wgfFuel'](1) != 12 or m['wgfFuel'](2) != 18 or m['wgfFuel'](0) >= m['wgfFuel'](1) or m['wgfFuel'](1) >= m['wgfFuel'](2)",
    }, {
      "note" = "every fire starts on 2d20 with the size adding 0/5/10 to the roll",
      "expr" = "m['wgfStartDie'](0) != 20 or m['wgfStartDie'](1) != 20 or m['wgfStartDie'](2) != 20 or m['wgfStartCount'](0) != 2 or m['wgfStartCount'](1) != 2 or m['wgfStartCount'](2) != 2 or m['wgfStartMod'](0) != 0 or m['wgfStartMod'](1) != 5 or m['wgfStartMod'](2) != 10",
    }, {
      "note" = "the refuel, wind resistance, capacity and visibility all step strictly up with size",
      "expr" = "m['wgfRefuel'](0) >= m['wgfRefuel'](1) or m['wgfRefuel'](1) >= m['wgfRefuel'](2) or m['wgfWindRes'](0) >= m['wgfWindRes'](1) or m['wgfWindRes'](1) >= m['wgfWindRes'](2) or m['wgfCapacity'](0) >= m['wgfCapacity'](1) or m['wgfCapacity'](1) >= m['wgfCapacity'](2) or m['wgfVisibility'](0) >= m['wgfVisibility'](1) or m['wgfVisibility'](1) >= m['wgfVisibility'](2)",
    } },
  "audit" = {
      "label" = "R474 WSG rest quality and fire pin audit",
      "comment" = "The Table 38 grids (the three fire sizes by fuel, start dice, refuel, wind resistance, capacity and visibility, plus the warmth-at-distance ladder with the dash-as-no-warmth sentinel), the eight rest-quality penalties with the plate-armor waivers, the no-rest threshold, the extreme-weather bar, the longer-sleep compensation, the armor donning and doffing discipline and the fire-function prose are audit examples.",
    },
}
