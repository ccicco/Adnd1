-- wfw: promoted from tools/spec_r467.json (the R467: the WSG FINDING WATER slice - the water-finding checks (two per day, extra searches automatically fail, the table not used where water is obviously and readily available), the snow-and-ice exception (water for the taking if the party can melt it, the figures assume no snow or ice cover, ice at 30 degrees or lower with the taint read from the table, freshly fallen snow the purest water in nature), the nearby-fresh-water and seacoast notes (the dig-to-the-water-table 100% above the high tide line and no more than two feet deep, the deeper the saltier) and Table 34: the chance of finding water grid by climate, terrain and season, printed p. 58 with the grid on p. 59.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 467,
  "prefix" = "wfw",
  "banner" = {
      "title" = "R467: the WSG FINDING WATER slice - the water-finding checks (two per day, extra searches automatically fail, the table not used where water is obviously and readily available), the snow-and-ice exception (water for the taking if the party can melt it, the figures assume no snow or ice cover, ice at 30 degrees or lower with the taint read from the table, freshly fallen snow the purest water in nature), the nearby-fresh-water and seacoast notes (the dig-to-the-water-table 100% above the high tide line and no more than two feet deep, the deeper the saltier) and Table 34: the chance of finding water grid by climate, terrain and season, printed p. 58 with the grid on p. 59.",
      "provenance" = "Ground truth four-way, a NEW WORKFLOW (the user decision this round): the user ran tesseract ON TERMUX over the pdfimages-extracted scan of printed p. 59 (poppler pdfimages -f 60, TSV output with word bounding boxes), and the grid was REBUILT FROM GEOMETRY - the terrain-code column at x 130-165, the season cells at x 190/285/385/480, one row per 20 pixels of y - instead of trusting any reader reading order. The tesseract reads cross-check against the pdfy embedded OCR layer and the djvu word layer: all three agree on every one of the 224 values. The slash-loss cells (tesseract 570, 5170, 60740, 30730, 70170) all resolve to the obvious xx/yy splits confirmed by the other two readers. The low-confidence terrain labels (subarctic E, temperate =%) resolve to F (forest) - vision confirmed, and forest is the missing terrain in both bands. The ONE contested value: Tropical swamp Spring reads 90/75 in BOTH text layers (tesseract conf 40, djvu 90/75, pdfy 90/75) but 90/80 in two vision reads; the USER READ THE PHYSICAL PAGE and settled it: 90/75 - the only taint value in the whole table not ending in 0, pinned as printed. The arctic rows are constant across all four seasons; the swamp rows carry the highest find chances; the desert rows the lowest. The seacoast and snow mechanics come from the same tesseract pass (the p59_full --psm 4 text) and the printed p. 58 intro from the pdfy layer, cross-checked against the user p58 tesseract run. The where-water-is-found section (the DM standing-water reduction and the water-table definition) stays in the p. 59 gap - NOT flipped this round.",
      "sentinel" = "All 224 Table 34 values pinned (the find% and the taint% per climate per terrain per season); the water-finding mechanics are audit examples, including the human-verified Tropical swamp 90/75 cell and the arctic constant rows.",
    },
  "consts" = { {
      "name" = "wfwRowCount",
      "value" = 28,
      "comment" = "the Table 34 row count: five climate bands x the terrain rows (arctic has no forest row; the other four climates run D/F/H/M/P/Sw)",
    }, {
      "name" = "wfwChecksPerDay",
      "value" = 2,
      "comment" = "a single character or a group traveling together can make two water-finding checks per day",
    }, {
      "name" = "wfwSeacoastDigPct",
      "value" = 100,
      "comment" = "in any seacoast area the chance of finding drinkable water by digging down to the water table is 100%",
    }, {
      "name" = "wfwSeacoastDigMaxFt",
      "value" = 2,
      "comment" = "the seacoast dig hole must be no more than two feet deep for the 100% chance to hold",
    }, {
      "name" = "wfwIceTempGate",
      "value" = 30,
      "comment" = "if the actual temperature is 30 degrees or lower, any water found in an area with no snow or ice cover will be in the form of ice",
    } },
  "bools" = { {
      "name" = "wfwExtraSearchAutoFail",
      "value" = true,
      "comment" = "searches conducted more often than two per day automatically fail",
    }, {
      "name" = "wfwNotUsedWhenObvious",
      "value" = true,
      "comment" = "the table should not be used in any circumstances where water is obviously and readily available",
    }, {
      "name" = "wfwNearbyFreshWaterTaintCheck",
      "value" = true,
      "comment" = "characters on the bank or shore of fresh water still use the table for the taint chance unless the water is known pure and drinkable",
    }, {
      "name" = "wfwSeaWaterDehydrates",
      "value" = true,
      "comment" = "drinking sea water actually dehydrates the character: the salt increases the body need for water, in large quantities or over a long period",
    }, {
      "name" = "wfwSeacoastDigAboveTide",
      "value" = true,
      "comment" = "the seacoast dig hole must be dug above the high tide line for the 100% chance to hold",
    }, {
      "name" = "wfwDigDeeperSaltier",
      "value" = true,
      "comment" = "the deeper one digs toward the seacoast water table, the saltier the water; digging too deep in one hole recovers water as undrinkable as the sea, though the loose soil filters out most of the salt near the surface",
    }, {
      "name" = "wfwRiverPurerUpstream",
      "value" = true,
      "comment" = "river water is more likely pure closer to the source than downstream",
    }, {
      "name" = "wfwLakePurerAtInflow",
      "value" = true,
      "comment" = "lake water is more likely pure where a river flows in than along the opposite shoreline where the water stagnates",
    }, {
      "name" = "wfwFastFlowPurer",
      "value" = true,
      "comment" = "fast-flowing water is generally more pure than standing water",
    }, {
      "name" = "wfwGroundWaterPurer",
      "value" = true,
      "comment" = "ground water, found by digging beneath the surface, is usually more pure than water found above the ground",
    }, {
      "name" = "wfwSnowIceCoverFreeWater",
      "value" = true,
      "comment" = "with snow or ice cover the water is there for the taking as long as characters are willing and able to melt the snow or ice",
    }, {
      "name" = "wfwTableAssumesNoSnowIce",
      "value" = true,
      "comment" = "the Table 34 figures assume that no snow or ice cover exists",
    }, {
      "name" = "wfwIceTaintPerTable",
      "value" = true,
      "comment" = "ice is no more free of foreign substances than the water it formed from: the percentage chance of tainted ice is taken from the table as if water had been found",
    }, {
      "name" = "wfwFreshSnowPurest",
      "value" = true,
      "comment" = "freshly fallen snow is the purest form of water available in nature; melted snow satisfies the water need as long as enough snow is available - a mere dusting provides little liquid",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "wfwFindWater",
      "tag" = "34",
      "count" = "wfwRowCount",
      "cols" = { "wfwWinFind", "wfwWinTaint", "wfwSprFind", "wfwSprTaint", "wfwSumFind", "wfwSumTaint", "wfwAutFind", "wfwAutTaint" },
      "col_default" = 0,
      "col_comments" = { "the Table 34 winter find% (left of the slash)", "the Table 34 winter taint% (right of the slash)", "the Table 34 spring find%", "the Table 34 spring taint%", "the Table 34 summer find%", "the Table 34 summer taint%", "the Table 34 autumn find%", "the Table 34 autumn taint%" },
      "row_comments" = { "the arctic desert row", "the arctic hills row", "the arctic mountains row", "the arctic plains row", "the subarctic desert row", "the subarctic forest row", "the subarctic hills row", "the subarctic mountains row", "the subarctic plains row", "the subarctic swamp row", "the temperate desert row", "the temperate forest row", "the temperate hills row", "the temperate mountains row", "the temperate plains row", "the temperate swamp row", "the subtropical desert row", "the subtropical forest row", "the subtropical hills row", "the subtropical mountains row", "the subtropical plains row", "the subtropical swamp row", "the tropical desert row", "the tropical forest row", "the tropical hills row", "the tropical mountains row", "the tropical plains row", "the tropical swamp row" },
      "data" = { { 5, 50, 5, 50, 5, 50, 5, 50 }, { 10, 50, 10, 50, 10, 50, 10, 50 }, { 5, 30, 5, 30, 5, 30, 5, 30 }, { 10, 50, 10, 50, 10, 50, 10, 50 }, { 5, 60, 10, 60, 10, 60, 5, 60 }, { 10, 40, 20, 40, 20, 50, 10, 40 }, { 5, 40, 10, 40, 15, 50, 10, 40 }, { 5, 30, 20, 30, 15, 30, 10, 30 }, { 10, 50, 20, 50, 20, 50, 15, 50 }, { 40, 60, 60, 60, 50, 60, 50, 60 }, { 5, 70, 5, 70, 5, 70, 5, 80 }, { 30, 30, 40, 30, 30, 30, 30, 30 }, { 30, 40, 40, 40, 40, 50, 30, 40 }, { 20, 30, 20, 30, 15, 30, 20, 30 }, { 20, 50, 40, 50, 40, 50, 30, 50 }, { 60, 70, 70, 70, 80, 80, 60, 70 }, { 5, 70, 5, 70, 5, 80, 5, 80 }, { 60, 40, 70, 50, 70, 60, 60, 50 }, { 30, 40, 50, 40, 50, 40, 40, 40 }, { 40, 30, 60, 40, 50, 50, 40, 40 }, { 20, 50, 40, 40, 30, 40, 20, 50 }, { 70, 70, 80, 70, 90, 80, 70, 80 }, { 5, 70, 10, 70, 5, 80, 5, 80 }, { 80, 50, 80, 60, 80, 70, 80, 60 }, { 15, 40, 20, 40, 30, 50, 15, 40 }, { 40, 30, 70, 30, 60, 40, 70, 40 }, { 20, 50, 50, 50, 60, 60, 50, 50 }, { 70, 70, 90, 75, 90, 80, 80, 80 } },
      "audit_comment" = "the Table 34 chance-of-finding-water grid (the find% and the taint% per climate band per terrain per season; arctic desert/hills/mountains/plains, subarctic through tropical desert/forest/hills/mountains/plains/swamp)",
    } },
  "chains" = {},
  "examples" = { {
      "note" = "the arctic desert row: 5/50 in all four seasons (the constant arctic rows)",
      "expr" = "m['wfwWinFind'](0) != 5 or m['wfwWinTaint'](0) != 50 or m['wfwSprFind'](0) != 5 or m['wfwSprTaint'](0) != 50 or m['wfwSumFind'](0) != 5 or m['wfwSumTaint'](0) != 50 or m['wfwAutFind'](0) != 5 or m['wfwAutTaint'](0) != 50",
    }, {
      "note" = "the arctic hills and plains rows: 10/50 constant; the arctic mountains row: 5/30 constant",
      "expr" = "m['wfwWinFind'](1) != 10 or m['wfwSprTaint'](1) != 50 or m['wfwSumFind'](1) != 10 or m['wfwAutTaint'](1) != 50 or m['wfwWinFind'](3) != 10 or m['wfwAutFind'](3) != 10 or m['wfwWinFind'](2) != 5 or m['wfwWinTaint'](2) != 30 or m['wfwAutTaint'](2) != 30",
    }, {
      "note" = "the subarctic swamp row: 40/60, 60/60, 50/60, 50/60",
      "expr" = "m['wfwWinFind'](9) != 40 or m['wfwWinTaint'](9) != 60 or m['wfwSprFind'](9) != 60 or m['wfwSprTaint'](9) != 60 or m['wfwSumFind'](9) != 50 or m['wfwSumTaint'](9) != 60 or m['wfwAutFind'](9) != 50 or m['wfwAutTaint'](9) != 60",
    }, {
      "note" = "the temperate swamp row: 60/70, 70/70, 80/80, 60/70",
      "expr" = "m['wfwWinFind'](15) != 60 or m['wfwWinTaint'](15) != 70 or m['wfwSprFind'](15) != 70 or m['wfwSprTaint'](15) != 70 or m['wfwSumFind'](15) != 80 or m['wfwSumTaint'](15) != 80 or m['wfwAutFind'](15) != 60 or m['wfwAutTaint'](15) != 70",
    }, {
      "note" = "the subtropical swamp row: 70/70, 80/70, 90/80, 70/80",
      "expr" = "m['wfwWinFind'](21) != 70 or m['wfwWinTaint'](21) != 70 or m['wfwSprFind'](21) != 80 or m['wfwSprTaint'](21) != 70 or m['wfwSumFind'](21) != 90 or m['wfwSumTaint'](21) != 80 or m['wfwAutFind'](21) != 70 or m['wfwAutTaint'](21) != 80",
    }, {
      "note" = "the tropical swamp row: 70/70, 90/75 (the human-verified odd cell), 90/80, 80/80",
      "expr" = "m['wfwWinFind'](27) != 70 or m['wfwWinTaint'](27) != 70 or m['wfwSprFind'](27) != 90 or m['wfwSprTaint'](27) != 75 or m['wfwSumFind'](27) != 90 or m['wfwSumTaint'](27) != 80 or m['wfwAutFind'](27) != 80 or m['wfwAutTaint'](27) != 80",
    }, {
      "note" = "the tropical forest row: 80/50, 80/60, 80/70, 80/60",
      "expr" = "m['wfwWinFind'](23) != 80 or m['wfwWinTaint'](23) != 50 or m['wfwSprFind'](23) != 80 or m['wfwSprTaint'](23) != 60 or m['wfwSumFind'](23) != 80 or m['wfwSumTaint'](23) != 70 or m['wfwAutFind'](23) != 80 or m['wfwAutTaint'](23) != 60",
    }, {
      "note" = "the temperate desert row: 5/70 x3 then the autumn 5/80; the subtropical and tropical desert rows",
      "expr" = "m['wfwWinFind'](10) != 5 or m['wfwWinTaint'](10) != 70 or m['wfwSprFind'](10) != 5 or m['wfwSprTaint'](10) != 70 or m['wfwSumFind'](10) != 5 or m['wfwSumTaint'](10) != 70 or m['wfwAutFind'](10) != 5 or m['wfwAutTaint'](10) != 80 or m['wfwWinFind'](16) != 5 or m['wfwWinTaint'](16) != 70 or m['wfwSprFind'](16) != 5 or m['wfwSprTaint'](16) != 70 or m['wfwSumFind'](16) != 5 or m['wfwSumTaint'](16) != 80 or m['wfwAutFind'](16) != 5 or m['wfwAutTaint'](16) != 80 or m['wfwWinFind'](22) != 5 or m['wfwWinTaint'](22) != 70 or m['wfwSprFind'](22) != 10 or m['wfwSprTaint'](22) != 70 or m['wfwSumFind'](22) != 5 or m['wfwSumTaint'](22) != 80 or m['wfwAutFind'](22) != 5 or m['wfwAutTaint'](22) != 80",
    }, {
      "note" = "the subarctic desert row: 5/60, 10/60, 10/60, 5/60",
      "expr" = "m['wfwWinFind'](4) != 5 or m['wfwWinTaint'](4) != 60 or m['wfwSprFind'](4) != 10 or m['wfwSprTaint'](4) != 60 or m['wfwSumFind'](4) != 10 or m['wfwSumTaint'](4) != 60 or m['wfwAutFind'](4) != 5 or m['wfwAutTaint'](4) != 60",
    }, {
      "note" = "the two-checks-per-day rule and the auto-fail gate",
      "expr" = "m['wfwChecksPerDay']() != 2",
    }, {
      "note" = "the seacoast dig: 100% if above the high tide line and no more than two feet deep",
      "expr" = "m['wfwSeacoastDigPct']() != 100 or m['wfwSeacoastDigMaxFt']() != 2",
    }, {
      "note" = "the ice temperature gate: 30 degrees or lower",
      "expr" = "m['wfwIceTempGate']() != 30",
    } },
  "audit" = {
      "label" = "R467 WSG finding water pin audit",
      "comment" = "The Table 34 grid value by value (the find% and the taint% per climate band per terrain per season, including the constant arctic rows and the human-verified tropical swamp spring cell), the two-checks-per-day rule with the auto-fail gate, the obvious-water exceptions (the snow and ice rules, the seacoast dig with its tide-line and depth gates) and the water-quality guidelines - every cell, const and bool verified against the model.",
    },
}
