-- wmp: promoted from tools/spec_r478.json (the R478: the WSG MEDICINAL PLANTS slice, printed p. 69 - the eighth camping-arc round, a TABLE round pinning Table 40: the availability of medicinal plants as two 34-row grids (the vegetation chance and the locate chance, four seasons apiece) over the terrain-climate frame (D, F, H, M, P, Se and Sw - Arctic with no swamp row), plus the slash entry semantics, the identify-half rule, the plant-lore always-correct rule, the search discipline and the worked example citing Appendix J in the DMG at pages 220-221.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 478,
  "prefix" = "wmp",
  "banner" = {
      "title" = "R478: the WSG MEDICINAL PLANTS slice, printed p. 69 - the eighth camping-arc round, a TABLE round pinning Table 40: the availability of medicinal plants as two 34-row grids (the vegetation chance and the locate chance, four seasons apiece) over the terrain-climate frame (D, F, H, M, P, Se and Sw - Arctic with no swamp row), plus the slash entry semantics, the identify-half rule, the plant-lore always-correct rule, the search discipline and the worked example citing Appendix J in the DMG at pages 220-221.",
      "provenance" = "The settle: the pdf layer DROPPED the entire leftmost terrain-code column and ALL five seacoast rows; tesseract kept the codes but garbled many slash cells (10110, 5110, 1510, 4010, 75140, 2010) and missed the seacoast rows plus the Arctic M row. Every contested cell was settled by targeted vision reads with two agreeing independent reads apiece (this round needed SEVEN reads); Arctic has no Sw row (six terrains, 34 rows total); and the book own worked example - tropical hills winter, vegetation 90 and locate 30 - independently confirms the settled row 29.",
      "sentinel" = "Bounds held by the grids: every vegetation chance stays in 0-100, every locate chance in 0-50; the identify cut is the locate chance halved.",
    },
  "consts" = { {
      "name" = "wmpClimateCount",
      "value" = 5,
      "comment" = "five climate bands: arctic through tropical",
    }, {
      "name" = "wmpTerrainCount",
      "value" = 7,
      "comment" = "seven terrain types per climate: D F H M P Se Sw",
    }, {
      "name" = "wmpArcticTerrainCount",
      "value" = 6,
      "comment" = "the arctic band has no Sw row - only six terrains",
    }, {
      "name" = "wmpRowCount",
      "value" = 34,
      "comment" = "Table 40 rows: 6 arctic plus four climates of 7",
    }, {
      "name" = "wmpAppendixJFirstPage",
      "value" = 220,
      "comment" = "Appendix J in the DMG starts at page 220",
    }, {
      "name" = "wmpAppendixJLastPage",
      "value" = 221,
      "comment" = "Appendix J in the DMG ends at page 221",
    }, {
      "name" = "wmpIdentifyNum",
      "value" = 1,
      "comment" = "the identify cut: the second roll at one-half or less",
    }, {
      "name" = "wmpIdentifyDen",
      "value" = 2,
      "comment" = "of the locate chance identifies the desired plant",
    }, {
      "name" = "wmpSearchesPerTurn",
      "value" = 1,
      "comment" = "one search per turn while the character keeps moving",
    }, {
      "name" = "wmpExVegPct",
      "value" = 90,
      "comment" = "the worked example: tropical hills winter vegetation 90",
    }, {
      "name" = "wmpExLocatePct",
      "value" = 30,
      "comment" = "the worked example: the locate chance for that cell",
    }, {
      "name" = "wmpExRoll",
      "value" = 15,
      "comment" = "the example second roll: the plant is the right type",
    }, {
      "name" = "wmpExWrongMinRoll",
      "value" = 16,
      "comment" = "rolls 16-30 find a plant of the wrong type, believed right",
    }, {
      "name" = "wmpExWrongMaxRoll",
      "value" = 30,
      "comment" = "the top of the wrong-type band equals the locate chance",
    }, {
      "name" = "wmpExFailMinRoll",
      "value" = 31,
      "comment" = "rolls above 30 find no medicinal plant at all",
    } },
  "bools" = { {
      "name" = "wmpVegChanceIsLeft",
      "value" = true,
      "comment" = "the left number of the slash is the vegetation chance",
    }, {
      "name" = "wmpLocateChanceIsRight",
      "value" = true,
      "comment" = "the right number is the one-turn locate chance",
    }, {
      "name" = "wmpUpperHalfWrongType",
      "value" = true,
      "comment" = "an upper-half roll finds the wrong type, assumed right",
    }, {
      "name" = "wmpPlantLoreAlwaysRight",
      "value" = true,
      "comment" = "plant lore proficiency always finds the desired type",
    }, {
      "name" = "wmpSearchByFunction",
      "value" = true,
      "comment" = "the search is by function, not by one specific plant",
    }, {
      "name" = "wmpKeepMoving",
      "value" = true,
      "comment" = "continual searching requires never re-searching an area",
    }, {
      "name" = "wmpRepeatSearchFails",
      "value" = true,
      "comment" = "repeated searches of one area auto-fail",
    }, {
      "name" = "wmpSearchSlowsMovement",
      "value" = true,
      "comment" = "the searcher concentrates and moves slowed",
    }, {
      "name" = "wmpDmMayAddPenalties",
      "value" = true,
      "comment" = "the DM may add surprise and reaction penalties",
    }, {
      "name" = "wmpDmGuardsAbuse",
      "value" = true,
      "comment" = "the DM may disregard rolls aimed at hoarding medicine",
    }, {
      "name" = "wmpArcticHasNoSwamp",
      "value" = true,
      "comment" = "the arctic band has no swamp terrain row",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "wmpVegChance",
      "tag" = "40v",
      "count" = "wmpRowCount",
      "cols" = { "wmpVegWinter", "wmpVegSpring", "wmpVegSummer", "wmpVegAutumn" },
      "col_comments" = { "Table 40 vegetation chance: winter", "Table 40 vegetation chance: spring", "Table 40 vegetation chance: summer", "Table 40 vegetation chance: autumn" },
      "col_default" = 0,
      "data" = { { 0, 5, 10, 0 }, { 5, 10, 10, 5 }, { 0, 0, 5, 0 }, { 5, 5, 10, 5 }, { 10, 10, 15, 10 }, { 10, 10, 10, 10 }, { 0, 5, 15, 5 }, { 70, 85, 100, 75 }, { 20, 30, 40, 25 }, { 10, 15, 20, 15 }, { 20, 30, 50, 30 }, { 25, 35, 50, 35 }, { 15, 20, 30, 20 }, { 10, 5, 5, 5 }, { 80, 90, 100, 90 }, { 65, 75, 90, 80 }, { 20, 30, 40, 30 }, { 50, 60, 75, 60 }, { 50, 65, 80, 65 }, { 30, 35, 40, 35 }, { 5, 5, 0, 5 }, { 90, 100, 100, 100 }, { 80, 90, 100, 95 }, { 40, 55, 75, 60 }, { 80, 90, 100, 100 }, { 80, 90, 100, 95 }, { 40, 50, 50, 50 }, { 5, 5, 0, 5 }, { 100, 100, 100, 100 }, { 90, 100, 100, 95 }, { 85, 90, 90, 90 }, { 100, 100, 100, 100 }, { 90, 95, 100, 95 }, { 50, 60, 70, 60 } },
      "audit_comment" = "the Table 40 vegetation chance grid (34 rows, the left slash number)",
    }, {
      "name" = "wmpLocateChance",
      "tag" = "40l",
      "count" = "wmpRowCount",
      "cols" = { "wmpLocWinter", "wmpLocSpring", "wmpLocSummer", "wmpLocAutumn" },
      "col_comments" = { "Table 40 locate chance: winter", "Table 40 locate chance: spring", "Table 40 locate chance: summer", "Table 40 locate chance: autumn" },
      "col_default" = 0,
      "data" = { { 0, 10, 10, 0 }, { 10, 10, 10, 10 }, { 0, 0, 20, 0 }, { 20, 20, 20, 20 }, { 10, 20, 20, 10 }, { 10, 20, 20, 10 }, { 0, 10, 10, 10 }, { 30, 30, 20, 30 }, { 20, 20, 30, 20 }, { 20, 20, 30, 20 }, { 20, 30, 30, 20 }, { 10, 20, 30, 20 }, { 10, 10, 10, 20 }, { 10, 10, 10, 20 }, { 30, 30, 30, 30 }, { 20, 30, 40, 20 }, { 20, 30, 30, 20 }, { 20, 30, 40, 20 }, { 20, 30, 30, 20 }, { 10, 20, 20, 10 }, { 10, 10, 0, 10 }, { 40, 40, 40, 40 }, { 40, 40, 50, 50 }, { 30, 40, 40, 30 }, { 40, 40, 40, 40 }, { 30, 30, 30, 30 }, { 10, 20, 20, 10 }, { 10, 10, 0, 10 }, { 40, 40, 30, 40 }, { 30, 30, 30, 30 }, { 40, 40, 30, 40 }, { 40, 40, 40, 30 }, { 30, 40, 40, 30 }, { 10, 10, 20, 10 } },
      "audit_comment" = "the Table 40 locate chance grid (34 rows, the right slash number)",
    } },
  "chains" = {},
  "examples" = { {
      "note" = "the row count: arctic lacks Sw, the other four climates carry all seven terrains",
      "expr" = "m['wmpRowCount']() != m['wmpArcticTerrainCount']() + 4 * m['wmpTerrainCount']()",
    }, {
      "note" = "the worked example cites tropical hills winter: vegetation 90, locate 30",
      "expr" = "m['wmpVegWinter'](29) != m['wmpExVegPct']() or m['wmpLocWinter'](29) != m['wmpExLocatePct']()",
    }, {
      "note" = "the example bands: 15 halves 30 exactly; 16-30 the wrong type; 31-up nothing",
      "expr" = "2 * m['wmpExRoll']() != m['wmpExLocatePct']() or m['wmpExWrongMaxRoll']() != m['wmpExLocatePct']() or m['wmpExFailMinRoll']() != m['wmpExLocatePct']() + 1 or m['wmpExWrongMinRoll']() != m['wmpExLocatePct']() / 2 + 1",
    }, {
      "note" = "the frame: five climates, seven terrains, arctic six, 34 rows; Appendix J spans DMG pages 220-221",
      "expr" = "m['wmpClimateCount']() != 5 or m['wmpTerrainCount']() != 7 or m['wmpArcticTerrainCount']() != 6 or m['wmpRowCount']() != 34 or m['wmpAppendixJLastPage']() != m['wmpAppendixJFirstPage']() + 1",
    }, {
      "note" = "the identify cut is one-half; one search per turn",
      "expr" = "m['wmpIdentifyNum']() * 2 != m['wmpIdentifyDen']() or m['wmpSearchesPerTurn']() != 1",
    } },
  "audit" = {
      "label" = "R478 WSG medicinal plants pin audit",
      "comment" = "The Table 40 terrain-climate grids (34 rows: Arctic six with no swamp, then subarctic, temperate, subtropical and tropical with all seven terrains apiece), the slash entry semantics (the left number the vegetation chance, the right the locate chance, identify on one-half or less, the upper half a wrong type believed right), plant lore always correct, one search per turn while moving, repeated searches auto-fail, movement slowed, and the worked example (tropical hills winter 90 and 30: roll 15 the right type, 16-30 wrong, 31-up nothing).",
    },
}
