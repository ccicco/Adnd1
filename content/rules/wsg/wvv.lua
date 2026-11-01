-- wvv: promoted from tools/spec_r434.json (the The WSG LAND-BASED VEHICLES, R434: Table 14 (the movement of vehicles - the 21 cart, chariot and wagon rows by the animal team x the normal and rugged terrain rates and the maximum load in gp; a 0 in the rugged column means the vehicle cannot go there) with the prose rules: the rates are miles per half-day, no vehicle can be taken into very rugged terrain (progress effectively negligible), the rates assume flat featureless ground or a path or roadway, and without such a path the terrain counts as one category more rugged for the vehicle (the lightly-forested example) - the round continues the encumbrance-and-movement chapter. Census 358 -> 359.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 434,
  "prefix" = "wvv",
  "banner" = {
      "title" = "The WSG LAND-BASED VEHICLES, R434: Table 14 (the movement of vehicles - the 21 cart, chariot and wagon rows by the animal team x the normal and rugged terrain rates and the maximum load in gp; a 0 in the rugged column means the vehicle cannot go there) with the prose rules: the rates are miles per half-day, no vehicle can be taken into very rugged terrain (progress effectively negligible), the rates assume flat featureless ground or a path or roadway, and without such a path the terrain counts as one category more rugged for the vehicle (the lightly-forested example) - the round continues the encumbrance-and-movement chapter. Census 358 -> 359.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 33; the user own copy OCR cross-checked against the archive djvu word layer (17 of 21 rows clean) and the IIIF full-resolution eye-reads (the chariot small/medium horse and the wagon rows garbled in the djvu; the eye-read values matched the user copy exactly); every number matched. The compiled-tables copy reads the cart medium/pony rugged cell as 6 - a djvu OCR error; the body text and the user copy both read 0.",
      "sentinel" = "The Table 14 movement figures are miles per half-day over normal and rugged terrain; a 0 rugged entry means the vehicle cannot be taken onto rugged terrain. The maximum load is the gp encumbrance value the vehicle and team can haul.",
    },
  "consts" = { {
      "name" = "wvvVehicleCount",
      "value" = 21,
      "comment" = "The Table 14 vehicle-row count.",
    }, {
      "name" = "wvvCartRowBase",
      "value" = 0,
      "comment" = "The cart rows begin at index 0 (small and medium carts, 8 rows).",
    }, {
      "name" = "wvvChariotRowBase",
      "value" = 8,
      "comment" = "The chariot rows begin at index 8 (small and large chariots, 6 rows).",
    }, {
      "name" = "wvvWagonRowBase",
      "value" = 14,
      "comment" = "The wagon rows begin at index 14 (small and large wagons, 7 rows).",
    } },
  "bools" = { {
      "name" = "wvvRateMilesPerHalfDay",
      "value" = true,
      "comment" = "The Table 14 rates are expressed in miles per half-day.",
    }, {
      "name" = "wvvNoVeryRugged",
      "value" = true,
      "comment" = "None of the vehicles can be taken into very rugged terrain - or, if they are, progress is so slow as to make large-scale movement effectively negligible.",
    }, {
      "name" = "wvvAssumesFlatOrPath",
      "value" = true,
      "comment" = "The given rates assume flat, featureless ground or a path or roadway.",
    }, {
      "name" = "wvvPathlessOneCategoryWorse",
      "value" = true,
      "comment" = "Without a path smooth and wide enough for the vehicle, treat the terrain as one category more rugged than it actually is.",
    }, {
      "name" = "wvvLightForestVehicleRugged",
      "value" = true,
      "comment" = "The lightly-forested example: normal terrain for a character on foot or mounted, but rugged for a vehicle without a suitable path.",
    }, {
      "name" = "wvvCartsWagonsHaulGear",
      "value" = true,
      "comment" = "Carts and wagons transport equipment (and possibly characters) over long distances.",
    }, {
      "name" = "wvvChariotsMainlyCharacters",
      "value" = true,
      "comment" = "Chariots are used mainly to transport characters; the larger ones can also haul equipment.",
    }, {
      "name" = "wvvMaxLoadIsGp",
      "value" = true,
      "comment" = "The maximum load column is the gp encumbrance value the vehicle and team can haul.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 14: the movement of vehicles",
      "tag" = "14",
      "count" = "wvvVehicleCount",
      "cols" = { "wvvMvNorm", "wvvMvRug", "wvvMaxLoad" },
      "col_default" = 0,
      "col_comments" = { "The normal-terrain rate in miles per half-day by vehicle row (the carts, the chariots and the wagons by their animal teams).", "The rugged-terrain rate in miles per half-day (0 = cannot be taken onto rugged terrain).", "The maximum load in gp of encumbrance value." },
      "data" = { { 8, 4, 3500 }, { 10, 5, 5500 }, { 12, 5, 6000 }, { 12, 7, 6000 }, { 6, 0, 4000 }, { 8, 3, 6500 }, { 8, 5, 7500 }, { 10, 6, 7500 }, { 6, 3, 3000 }, { 9, 5, 4000 }, { 10, 6, 4000 }, { 12, 7, 5500 }, { 14, 8, 5500 }, { 16, 10, 5500 }, { 8, 3, 7500 }, { 10, 6, 8500 }, { 12, 9, 9000 }, { 10, 6, 12000 }, { 12, 8, 13500 }, { 14, 8, 13500 }, { 16, 10, 15000 } },
      "audit_comment" = "the Table 14 grid: the 21 vehicle rows (the small and medium carts, the small and large chariots, the small and large wagons, each by its animal team) x the normal and rugged rates and the maximum loads",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['wvvMvNorm'](0) != 8 or m['wvvMvRug'](0) != 4 or m['wvvMaxLoad'](0) != 3500",
      "note" = "the small cart drawn by a pony: 8 and 4 miles per half-day, a 3500 gp maximum load",
    }, {
      "expr" = "m['wvvMvNorm'](4) != 6 or m['wvvMvRug'](4) != 0",
      "note" = "the medium cart drawn by a pony cannot be taken onto rugged terrain (0)",
    }, {
      "expr" = "m['wvvMvNorm'](13) != 16 or m['wvvMvRug'](13) != 10 or m['wvvMaxLoad'](13) != 5500",
      "note" = "the large chariot drawn by heavy horses: the fastest vehicle, 16 and 10 miles per half-day, a 5500 gp load",
    }, {
      "expr" = "m['wvvMvNorm'](17) != 10 or m['wvvMvRug'](17) != 6 or m['wvvMaxLoad'](17) != 12000",
      "note" = "the large wagon drawn by light horses: 10 and 6, a 12000 gp load",
    }, {
      "expr" = "m['wvvMaxLoad'](20) != 15000",
      "note" = "the large wagon drawn by heavy horses hauls the most: 15000 gp",
    } },
  "audit" = {
      "label" = "R434 WSG vehicles pin audit",
      "comment" = "The land-based vehicles slice pins Table 14 (the 21 cart, chariot and wagon rows x the normal and rugged rates and the maximum loads), the miles-per-half-day scale, the no-very-rugged rule and the pathless one-category-worse rule (rules/wsgvehicle.h, prefix wvv); census 358 -> 359.",
    },
}
