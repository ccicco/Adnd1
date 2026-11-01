-- dnu: promoted from tools/spec_r518.json (the The DSG UNDERGROUND WATER TRAVEL, R518: printed pp. 46-48 (pdf 47-49) - the water travel opener (the deepening riverbeds lifting old access tunnels a dozen or more feet above the water, the low ceiling making boat travel impossible, the absent weather against the winding passages, the folding boat and the weaker collapsible boats and the creature boats of inhabited regions, and the scale cut-out model for tight bends), the Table 21 movement rates grid (the eight boat types from the small rowboat 90/120 through the large barge 20/30 to the small canoe and kayak at 120/180, subject to water flow, with maximum speed counting as hard work), the Table 22 standstill grid (1/3 rounds for the small rowboat up to 5/10 for the large barge), the movement-relative-to-water-only rule with the 60-ft stream and 90-ft canoe netting 30 upstream and 150 downstream, the Table 23 draught and ceilings grid (from the 1/2-ft small rowboat under a 2-ft ceiling to the 1-ft large barge under 4 ft), the Table 24 nonproficiency penalties (the -30/-15/-15/-10/-5/-60/-30/-60 movement modifiers and the 5/10/0/0/0/20/10/25 capsize chances), the one-proficient-stops-capsize and half-proficient-stops-penalty exemptions, the collision rules (the lantern and beacon and infravision, the vision-range rule, the d100 blind-travel check), the Table 25 collision probability grid (narrow 1-5-20/10-20-40, average 0-2-10/5-10-20, wide 0-0-4/1-4-8 proficient/nonproficient), the 5%-per-30-ft damage math with the 15% example and the difference-reading hull damage, the Table 26 boat damage grid (the eight percent bands from the 01-05 slight leak through the 45-60 hull split to the 99-00 no damage), the drop-off rules (5% per foot for damage and capsize, the 99/00 miraculous survival, the Proficiency Check save), the bailing rules (strenuous exercise, one character canceling one small hole), and the capsizing rules (the loose objects, the 1d4-round refloat, the float-downstream rescue, and the boatwright repair seam));
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 518,
  "prefix" = "dnu",
  "banner" = {
      "title" = "The DSG UNDERGROUND WATER TRAVEL, R518: printed pp. 46-48 (pdf 47-49) - the water travel opener (the deepening riverbeds lifting old access tunnels a dozen or more feet above the water, the low ceiling making boat travel impossible, the absent weather against the winding passages, the folding boat and the weaker collapsible boats and the creature boats of inhabited regions, and the scale cut-out model for tight bends), the Table 21 movement rates grid (the eight boat types from the small rowboat 90/120 through the large barge 20/30 to the small canoe and kayak at 120/180, subject to water flow, with maximum speed counting as hard work), the Table 22 standstill grid (1/3 rounds for the small rowboat up to 5/10 for the large barge), the movement-relative-to-water-only rule with the 60-ft stream and 90-ft canoe netting 30 upstream and 150 downstream, the Table 23 draught and ceilings grid (from the 1/2-ft small rowboat under a 2-ft ceiling to the 1-ft large barge under 4 ft), the Table 24 nonproficiency penalties (the -30/-15/-15/-10/-5/-60/-30/-60 movement modifiers and the 5/10/0/0/0/20/10/25 capsize chances), the one-proficient-stops-capsize and half-proficient-stops-penalty exemptions, the collision rules (the lantern and beacon and infravision, the vision-range rule, the d100 blind-travel check), the Table 25 collision probability grid (narrow 1-5-20/10-20-40, average 0-2-10/5-10-20, wide 0-0-4/1-4-8 proficient/nonproficient), the 5%-per-30-ft damage math with the 15% example and the difference-reading hull damage, the Table 26 boat damage grid (the eight percent bands from the 01-05 slight leak through the 45-60 hull split to the 99-00 no damage), the drop-off rules (5% per foot for damage and capsize, the 99/00 miraculous survival, the Proficiency Check save), the bailing rules (strenuous exercise, one character canceling one small hole), and the capsizing rules (the loose objects, the 1d4-round refloat, the float-downstream rescue, and the boatwright repair seam)",
      "provenance" = "the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf = printed + 1; the text read from the IA djvu OCR (djvu.txt lines ~5963-6300) with the pdf Acrobat-Capture layer as the second read (idx 63-65 = printed pp. 46-48) - every numeric cell dual-confirmed: the six tables reconstructed positionally from the Capture Tm coordinates where the djvu columns garble (Oar/Paddie, ftir, bargelraft, 1/28, 112ft, 114 ft, 113 ft, lft, 4%, dlOO, 4100 = d100, 2096 = 20%, 1096/1596 = 10%/15%). The Tables 21-24 share one boat key order (small rowboat, coracle, large rowboat, small barge/raft, large barge, small canoe, large canoe, kayak). The DMG page 54 movement seam and the DSG page 25 boatwright seam are noted. The Mining section (Where to Mine, p. 48) starts the NEXT round per the content-density rule.",
      "sentinel" = "Six tables pin in one round, the most since the cave-in arcs: Table 21 (8x2 speeds), Table 22 (8x2 standstill rounds), Table 23 (8x2 with the fractions pinned as whole units - draught in inches, ceiling in half-feet - so 1/3 ft pins as 4 inches and 1 1/2 ft as 3 half-feet), Table 24 (8x2 with the movement penalties as positive magnitudes, minus in the name and comment per the R514 convention), Table 25 (9 rows keyed width x 3 + flow, proficient and nonproficient percents), and Table 26 (8 lo/hi bands with 00 read as 100; the hull-split band pins as 45-60 exactly as printed, overlapping the 21-45 large-holes band at 45 - the R517 overlap lesson: pin as printed, never repair the book). Every effect die pins as dice + sides consts per the R508 convention (1d6 hours, 2d4+2 turns, 2d4, 1d6 rounds, 1d6 pieces, 1d4 refloat rounds). The DMG page 54 and DSG page 25 seams are noted; nothing auto-credits.",
    },
  "consts" = { {
      "name" = "dnuT21RowCount",
      "value" = 8,
      "comment" = "the Table 21 boat movement rates grid carries eight boat types.",
    }, {
      "name" = "dnuT22RowCount",
      "value" = 8,
      "comment" = "the Table 22 standstill grid carries the same eight boat types.",
    }, {
      "name" = "dnuT23RowCount",
      "value" = 8,
      "comment" = "the Table 23 draught and ceilings grid carries the same eight boat types.",
    }, {
      "name" = "dnuT24RowCount",
      "value" = 8,
      "comment" = "the Table 24 nonproficiency grid carries the same eight boat types.",
    }, {
      "name" = "dnuT25RowCount",
      "value" = 9,
      "comment" = "the Table 25 collision probability grid carries nine cells: the three waterway widths against the placid, medium and rapid flow bands.",
    }, {
      "name" = "dnuT26RowCount",
      "value" = 8,
      "comment" = "the Table 26 boat damage grid carries eight percent-damage bands.",
    }, {
      "name" = "dnuExampleStreamFtPerRound",
      "value" = 60,
      "comment" = "the worked example: a stream flowing 60 feet per round.",
    }, {
      "name" = "dnuExampleCanoeFtPerRound",
      "value" = 90,
      "comment" = "a canoe traveling upstream at 90 feet per round in that stream.",
    }, {
      "name" = "dnuExampleUpstreamNetFt",
      "value" = 30,
      "comment" = "the upstream canoe is actually only moving 30 feet per round past the bank - boat movement is relative to the water only.",
    }, {
      "name" = "dnuExampleDownstreamFt",
      "value" = 150,
      "comment" = "the same canoe traveling downstream streaks along at 150 feet per round relative to the stream's bank.",
    }, {
      "name" = "dnuDamageBasePctPerSlice",
      "value" = 5,
      "comment" = "the base chance of suffering collision damage is 5% for each 30-feet-per-round slice of the boat's speed.",
    }, {
      "name" = "dnuDamageSpeedSliceFt",
      "value" = 30,
      "comment" = "the speed slice of the collision damage formula: 30 feet per round.",
    }, {
      "name" = "dnuExampleDamagePct",
      "value" = 15,
      "comment" = "the worked example: a boat traveling 90 feet per round has a damage probability of 15%.",
    }, {
      "name" = "dnuExampleHullDamagePct",
      "value" = 10,
      "comment" = "the worked example: a damage roll of 05 against the 15% probability is 10% less, so the boat's hull has suffered 10% damage - the hull damage is the difference between the die roll and the damage probability.",
    }, {
      "name" = "dnuDropoffDamagePctPerFoot",
      "value" = 5,
      "comment" = "a boat plunging over a drop-off checks for damage just as in a collision, but the chance is 5% per one foot of the drop-off, not based upon the boat's speed.",
    }, {
      "name" = "dnuDropoffCapsizePctPerFoot",
      "value" = 5,
      "comment" = "the chance of capsizing over a drop-off is also 5% per one foot of drop-off.",
    }, {
      "name" = "dnuRefloatRoundsDice",
      "value" = 1,
      "comment" = "it takes 1d4 rounds to refloat a capsized boat.",
    }, {
      "name" = "dnuRefloatRoundsSides",
      "value" = 4,
      "comment" = "the sides of the 1d4-round refloating roll, pinned as dice + sides consts per the R508 convention.",
    }, {
      "name" = "dnuT26SlightLeakHoursDice",
      "value" = 1,
      "comment" = "the 01-05 band: the boat leaks slightly and will founder after 1d6 hours.",
    }, {
      "name" = "dnuT26SlightLeakHoursSides",
      "value" = 6,
      "comment" = "the sides of the 1d6-hour slight-leak roll.",
    }, {
      "name" = "dnuT26SmallHoleTurnsDice",
      "value" = 2,
      "comment" = "the 06-10 band: water pours in from a small hole and the boat founders in 2d4 + 2 turns.",
    }, {
      "name" = "dnuT26SmallHoleTurnsSides",
      "value" = 4,
      "comment" = "the sides of the 2d4-turn small-hole roll.",
    }, {
      "name" = "dnuT26SmallHoleBonusTurns",
      "value" = 2,
      "comment" = "the +2 turns added to the small-hole 2d4 foundering roll.",
    }, {
      "name" = "dnuT26ManyHolesDice",
      "value" = 2,
      "comment" = "the 11-20 band: water pours in from 2d4 small holes and the boat founders in 2d4 turns - both rolls share the 2d4 shape.",
    }, {
      "name" = "dnuT26ManyHolesSides",
      "value" = 4,
      "comment" = "the sides of the 2d4 rolls for the many-holes band.",
    }, {
      "name" = "dnuT26LargeHoleRoundsDice",
      "value" = 1,
      "comment" = "the 21-45 band: large holes in the hull, the boat founders in 1d6 rounds.",
    }, {
      "name" = "dnuT26LargeHoleRoundsSides",
      "value" = 6,
      "comment" = "the sides of the 1d6-round large-hole roll.",
    }, {
      "name" = "dnuT26PiecesDice",
      "value" = 1,
      "comment" = "the 61-80 band: the boat breaks into 1d6 pieces.",
    }, {
      "name" = "dnuT26PiecesSides",
      "value" = 6,
      "comment" = "the sides of the 1d6-pieces roll.",
    } },
  "bools" = { {
      "name" = "dnuRiverbedDeepeningRaisesTunnels",
      "value" = true,
      "comment" = "the torrents of rushing water gouge their channels, so riverbeds grow deeper and access tunnels that once fed into a river below its surface may now end a dozen or more feet above the water.",
    }, {
      "name" = "dnuLowCeilingBlocksBoatTravel",
      "value" = true,
      "comment" = "the water might be deep enough for the heaviest of boats, but if the ceiling drops to within a few feet of the water, travel by boat is quite impossible.",
    }, {
      "name" = "dnuWeatherAbsentUnderground",
      "value" = true,
      "comment" = "the dangers presented by weather are generally absent from the underground; low ceilings and tortuously winding passages create the replacement problems.",
    }, {
      "name" = "dnuFoldingBoatIdeal",
      "value" = true,
      "comment" = "enchanted vessels such as the folding boat are ideal for dungeon adventuring, since they can easily be carried through narrow passages and down stairways.",
    }, {
      "name" = "dnuCollapsibleBoatsWeaker",
      "value" = true,
      "comment" = "collapsible boats, while expensive and weaker than normal boats, provide another means of traversing underground waters.",
    }, {
      "name" = "dnuCreatureBoatsAcquirable",
      "value" = true,
      "comment" = "in inhabited or heavily traveled regions characters might find boats used by underground creatures - borrowed, bought, or otherwise acquired.",
    }, {
      "name" = "dnuScaleModelForTightBends",
      "value" = true,
      "comment" = "when carrying a boat into a dungeon the DM must note the boat dimensions against the passage sizes; in tight series of turns a scale cut-out model of the boat over a detailed corridor map shows whether it fits.",
    }, {
      "name" = "dnuMovementRelativeToWaterOnly",
      "value" = true,
      "comment" = "boat movement is relative to the water only; the rate must be combined with (added to or subtracted from) the water movement to get the movement relative to land.",
    }, {
      "name" = "dnuMaxSpeedIsHardWork",
      "value" = true,
      "comment" = "a character propelling a boat at maximum speed is considered to be working hard for purposes of the fatigue and exhaustion rules.",
    }, {
      "name" = "dnuCoastingReverseOfAcceleration",
      "value" = true,
      "comment" = "the acceleration procedure applies in reverse to determine how long a boat continues coasting forward when its crew attempts to stop it.",
    }, {
      "name" = "dnuRatesAssumeProficientCrew",
      "value" = true,
      "comment" = "the listed movement rates assume at least one character helping to propel the boat has boating proficiency.",
    }, {
      "name" = "dnuMoveModifierEachRound",
      "value" = true,
      "comment" = "the nonproficiency movement modifier is applied to each round of operation at normal or maximum speed.",
    }, {
      "name" = "dnuCapsizeOnEntryExitAndRisky",
      "value" = true,
      "comment" = "the capsize chance is rolled each time a character enters or leaves the boat and on any other occasions the DM feels are risky - turning around in a mild current, retrieving something from the water, standing up.",
    }, {
      "name" = "dnuOneProficientStopsCapsize",
      "value" = true,
      "comment" = "if at least one person with boating proficiency is present in the boat, the capsize chance does not apply.",
    }, {
      "name" = "dnuHalfProficientStopsPenalty",
      "value" = true,
      "comment" = "if at least half of the characters paddling or rowing have boating proficiency, the movement penalties do not apply.",
    }, {
      "name" = "dnuPenaltiesAssumeMediumOrSlower",
      "value" = true,
      "comment" = "all of the nonproficiency penalties assume the boat moves through water of medium flow or slower; riding rapids or cascades is much more challenging.",
    }, {
      "name" = "dnuLanternAvoidsDarkCollisions",
      "value" = true,
      "comment" = "a boat that carries a lantern or beacon can light the water before it sufficiently to avoid collisions due to darkness; if the light is snuffed or the progress is especially fast, the danger of smashing into a rock becomes very real.",
    }, {
      "name" = "dnuVisionRuleAvoidsCollisions",
      "value" = true,
      "comment" = "obstacles can be avoided if the range of vision of the characters on board is greater than the distance the boat travels in one round.",
    }, {
      "name" = "dnuInfravisionCanNavigate",
      "value" = true,
      "comment" = "infravision is sufficiently sensitive to the differences between the water and its bed to navigate a boat.",
    }, {
      "name" = "dnuBlindTravelChecksEachRound",
      "value" = true,
      "comment" = "if vision does not extend far enough, the craft must check each round it travels blind, rolling d100 against the Table 25 collision percentage (the djvu garble 4100 = d100, settled by the Capture dlOO read).",
    }, {
      "name" = "dnuDamageCheckIsD100",
      "value" = true,
      "comment" = "when a collision is indicated, roll d100 again and compare to the damage probability; a result equal to or less means the boat sustains damage.",
    }, {
      "name" = "dnuHullDamageIsDifference",
      "value" = true,
      "comment" = "the exact extent of collision damage is the difference between the die roll and the damage probability, expressed as a percent of the boat's hull strength.",
    }, {
      "name" = "dnuDropoffMiraculousSurvival",
      "value" = true,
      "comment" = "any time the drop-off damage roll is made and the result is 99 or 00, the boat miraculously survives the fall undamaged.",
    }, {
      "name" = "dnuCapsizeProficiencyCheckPrevents",
      "value" = true,
      "comment" = "if a drop-off capsize is indicated but a character with boating proficiency is aboard, any one such character can attempt a Proficiency Check; success means the capsize was prevented.",
    }, {
      "name" = "dnuBailingStrenuousUnlessSlight",
      "value" = true,
      "comment" = "characters not rowing or steering can bail water from a ruptured hull; bailing is strenuous exercise for the fatigue and exhaustion rules unless the boat is only leaking slightly.",
    }, {
      "name" = "dnuBailingCancelsOneSmallHole",
      "value" = true,
      "comment" = "a single character can bail enough water to cancel the effects of one small hole in the hull, given a suitable container and all of his time devoted to bailing.",
    }, {
      "name" = "dnuCapsizeDropsLooseObjects",
      "value" = true,
      "comment" = "a capsized boat tips over and fills with water; all loose objects fall free and must be recovered individually.",
    }, {
      "name" = "dnuRecoveryImpossibleInRapidWater",
      "value" = true,
      "comment" = "in rapidly moving water, recovery of scattered items is usually impossible.",
    }, {
      "name" = "dnuCapsizedBoatsDoNotSink",
      "value" = true,
      "comment" = "capsized boats do not sink, so characters unable to get their footing can hang onto the boat and float downstream until they can refloat it.",
    }, {
      "name" = "dnuDamageRequiresRepairBeforeRefloat",
      "value" = true,
      "comment" = "if the boat was damaged when it capsized, the holes must be repaired before refloating (see the boatwright proficiency on DSG page 25).",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 21: BOAT MOVEMENT RATES",
      "tag" = "21",
      "count" = "dnuT21RowCount",
      "sentinel" = -99,
      "col_default" = -99,
      "cols" = { "dnuT21NormalFt", "dnuT21MaxFt" },
      "col_comments" = { "the normal oar/paddle speed in feet per round, subject to the speed and direction of water flow: 0 small rowboat 90, 1 coracle 30, 2 large rowboat 45, 3 small barge/raft 30, 4 large barge 20, 5 small canoe 120, 6 large canoe 90, 7 kayak 120.", "the maximum oar/paddle speed in feet per round: 0 small rowboat 120, 1 coracle 45, 2 large rowboat 60, 3 small barge/raft 45, 4 large barge 30, 5 small canoe 180, 6 large canoe 120, 7 kayak 180." },
      "audit_comment" = "the Table 21 boat movement rates grid (the djvu garble Oar/Paddie = Oar/Paddle)",
      "data" = { { 90, 120 }, { 30, 45 }, { 45, 60 }, { 30, 45 }, { 20, 30 }, { 120, 180 }, { 90, 120 }, { 120, 180 } },
    }, {
      "name" = "Table 22: MOVEMENT FROM A STANDSTILL POSITION",
      "tag" = "22",
      "count" = "dnuT22RowCount",
      "sentinel" = -99,
      "col_default" = -99,
      "cols" = { "dnuT22ToNormalRounds", "dnuT22ToMaxRounds" },
      "col_comments" = { "rounds to reach normal speed from a standstill: 0 small rowboat 1, 1 coracle 1, 2 large rowboat 2, 3 small barge/raft 2, 4 large barge 5, 5 small canoe 1, 6 large canoe 1, 7 kayak 1.", "rounds to reach maximum speed from a standstill: 0 small rowboat 3, 1 coracle 3, 2 large rowboat 5, 3 small barge/raft 6, 4 large barge 10, 5 small canoe 2, 6 large canoe 3, 7 kayak 2." },
      "audit_comment" = "the Table 22 standstill grid",
      "data" = { { 1, 3 }, { 1, 3 }, { 2, 5 }, { 2, 6 }, { 5, 10 }, { 1, 2 }, { 1, 3 }, { 1, 2 } },
    }, {
      "name" = "Table 23: BOAT DRAUGHT AND CEILINGS",
      "tag" = "23",
      "count" = "dnuT23RowCount",
      "sentinel" = -99,
      "col_default" = -99,
      "cols" = { "dnuT23DraughtInches", "dnuT23CeilingHalfFeet" },
      "col_comments" = { "the depth of water required below the surface, pinned in inches: 0 small rowboat 1/2 ft = 6, 1 coracle 1/2 ft = 6, 2 large rowboat 3/4 ft = 9, 3 small barge/raft 3/4 ft = 9, 4 large barge 1 ft = 12, 5 small canoe 1/4 ft = 3, 6 large canoe 1/3 ft = 4, 7 kayak 1/4 ft = 3.", "the minimum ceiling needed to pass unimpeded, pinned in half-feet: 0 small rowboat 2 ft = 4, 1 coracle 3 ft = 6, 2 large rowboat 3 ft = 6, 3 small barge/raft 3 ft = 6, 4 large barge 4 ft = 8, 5 small canoe 1 1/2 ft = 3, 6 large canoe 2 ft = 4, 7 kayak 1 1/2 ft = 3." },
      "audit_comment" = "the Table 23 draught and ceilings grid (fractions pinned as whole units: draught in inches, ceiling in half-feet)",
      "data" = { { 6, 4 }, { 6, 6 }, { 9, 6 }, { 9, 6 }, { 12, 8 }, { 3, 3 }, { 4, 4 }, { 3, 3 } },
    }, {
      "name" = "Table 24: NONPROFICIENCY PENALTIES FOR BOAT USE",
      "tag" = "24",
      "count" = "dnuT24RowCount",
      "sentinel" = -99,
      "col_default" = -99,
      "cols" = { "dnuT24MovePenaltyFtPerRound", "dnuT24CapsizePct" },
      "col_comments" = { "the nonproficiency movement modifier pinned as a positive magnitude with the minus in this name and comment, applied each round at normal or maximum speed: 0 small rowboat -30, 1 coracle -15, 2 large rowboat -15, 3 small barge/raft -10, 4 large barge -5, 5 small canoe -60, 6 large canoe -30, 7 kayak -60.", "the capsize chance percent, rolled on entering or leaving the boat and other risky occasions: 0 small rowboat 5%, 1 coracle 10%, 2 large rowboat 0, 3 small barge/raft 0, 4 large barge 0, 5 small canoe 20% (the djvu garble 2096 = 20%), 6 large canoe 10%, 7 kayak 25%." },
      "audit_comment" = "the Table 24 nonproficiency penalties grid",
      "data" = { { 30, 5 }, { 15, 10 }, { 15, 0 }, { 10, 0 }, { 5, 0 }, { 60, 20 }, { 30, 10 }, { 60, 25 } },
    }, {
      "name" = "Table 25: COLLISION PROBABILITY",
      "tag" = "25",
      "count" = "dnuT25RowCount",
      "sentinel" = -99,
      "col_default" = -99,
      "cols" = { "dnuT25ProfPct", "dnuT25NonprofPct" },
      "col_comments" = { "the collision percent with boating proficiency (the number before the slash), rows 0-2 narrow / 3-5 average / 6-8 wide against placid, medium and rapid flow: narrow 1/5/20, average 0/2/10, wide 0/0/4.", "the collision percent without boating proficiency (the number after the slash): narrow 10/20/40, average 5/10/20, wide 1/4/8." },
      "audit_comment" = "the Table 25 collision probability grid (row key = width x 3 + flow: 0 narrow placid through 8 wide rapid)",
      "data" = { { 1, 10 }, { 5, 20 }, { 20, 40 }, { 0, 5 }, { 2, 10 }, { 10, 20 }, { 0, 1 }, { 0, 4 }, { 4, 8 } },
    }, {
      "name" = "Table 26: BOAT DAMAGE",
      "tag" = "26",
      "count" = "dnuT26RowCount",
      "sentinel" = -99,
      "col_default" = -99,
      "cols" = { "dnuT26Lo", "dnuT26Hi" },
      "col_comments" = { "the low end of the percent-damage band: 0 leaks slightly at 01, 1 small hole at 06, 2 many holes at 11, 3 large holes at 21, 4 hull splits at 45, 5 breaks into 1d6 pieces at 61, 6 splinters at 81, 7 no damage at 99.", "the high end of the percent-damage band with 00 read as 100: 05, 10, 20, 45, 60, 80, 98, 100." },
      "audit_comment" = "the Table 26 boat damage grid",
      "data" = { { 1, 5 }, { 6, 10 }, { 11, 20 }, { 21, 45 }, { 45, 60 }, { 61, 80 }, { 81, 98 }, { 99, 100 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dnuExampleStreamFtPerRound']() != 60 or m['dnuExampleCanoeFtPerRound']() != 90 or m['dnuExampleUpstreamNetFt']() != 30 or m['dnuExampleDownstreamFt']() != 150",
      "note" = "the relative-movement example: the 90-ft canoe in the 60-ft stream nets 30 ft/round upstream and 150 downstream.",
    }, {
      "expr" = "m['dnuDamageBasePctPerSlice']() != 5 or m['dnuDamageSpeedSliceFt']() != 30 or m['dnuExampleDamagePct']() != 15 or m['dnuExampleHullDamagePct']() != 10",
      "note" = "the collision damage math: 5% per 30 ft/round of speed, the 90-ft boat at 15%, and the 05 roll meaning 10% hull damage.",
    }, {
      "expr" = "m['dnuDropoffDamagePctPerFoot']() != 5 or m['dnuDropoffCapsizePctPerFoot']() != 5 or m['dnuRefloatRoundsDice']() != 1 or m['dnuRefloatRoundsSides']() != 4",
      "note" = "the drop-off checks at 5% per foot for both damage and capsize, and the 1d4-round refloating of a capsized boat.",
    }, {
      "expr" = "m['dnuT26SlightLeakHoursDice']() != 1 or m['dnuT26SlightLeakHoursSides']() != 6 or m['dnuT26SmallHoleTurnsDice']() != 2 or m['dnuT26SmallHoleTurnsSides']() != 4 or m['dnuT26SmallHoleBonusTurns']() != 2 or m['dnuT26ManyHolesDice']() != 2 or m['dnuT26ManyHolesSides']() != 4 or m['dnuT26LargeHoleRoundsDice']() != 1 or m['dnuT26LargeHoleRoundsSides']() != 6 or m['dnuT26PiecesDice']() != 1 or m['dnuT26PiecesSides']() != 6",
      "note" = "the Table 26 effect dice: the slight-leak 1d6 hours, the small-hole 2d4+2 turns, the many-holes 2d4 holes and 2d4 turns, the large-hole 1d6 rounds, and the 1d6 pieces.",
    } },
  "audit" = {
      "label" = "R518 DSG water travel audit",
      "comment" = "The DSG water travel pins the underground boating rules (the deepening riverbeds raising old access tunnels, the low-ceiling impossibility, the folding and collapsible and creature boats, the scale-model test for tight bends, the Table 21 eight-boat movement grid with the Table 22 standstill rounds, the movement-relative-to-water-only rule with the 30/150 upstream-downstream example, the Table 23 draught and ceiling minima pinned in inches and half-feet, the Table 24 nonproficiency movement penalties and capsize chances with the one-proficient and half-proficient exemptions and the medium-or-slower assumption, the collision rules with the lantern and infravision and vision-range readings, the Table 25 narrow/average/wide placid/medium/rapid collision grid, the 5%-per-30-ft damage math with the difference-reading hull damage, the Table 26 eight-band damage grid with its 1d6-hour, 2d4+2-turn, 2d4-turn, 1d6-round and 1d6-piece effects, the drop-off checks at 5% per foot with the 99/00 miraculous survival and the Proficiency Check capsize save, the bailing rules canceling one small hole per character, and the capsizing rules with the 1d4-round refloat and the boatwright repair seam).",
    },
}
