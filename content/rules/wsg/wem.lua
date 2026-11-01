-- wem: promoted from tools/spec_r432.json (the The WSG ENCUMBRANCE AND MOVEMENT, R432: Table 11 (the encumbrance limits for characters - the 14 strength rows x the Light/Moderate/Heavy/Severe ranges, each category begins at the previous one over) and Table 12 (the character movement on foot - the encumbrance category x the normal/rugged/very-rugged terrain class, the normal and the accelerated miles per half-day) with the bulk rule-of-thumb, the terrain definitions and the large-scale overland movement rules - the round opens the encumbrance-and-movement chapter. Census 356 -> 357.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 432,
  "prefix" = "wem",
  "banner" = {
      "title" = "The WSG ENCUMBRANCE AND MOVEMENT, R432: Table 11 (the encumbrance limits for characters - the 14 strength rows x the Light/Moderate/Heavy/Severe ranges, each category begins at the previous one over) and Table 12 (the character movement on foot - the encumbrance category x the normal/rugged/very-rugged terrain class, the normal and the accelerated miles per half-day) with the bulk rule-of-thumb, the terrain definitions and the large-scale overland movement rules - the round opens the encumbrance-and-movement chapter. Census 356 -> 357.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 30-31; the user own copy OCR cross-checked against the archive djvu word layer and the IIIF eye-read; the disputed 18/01-50 severe cell read 1751-2500 at full resolution (the half-resolution vision 2250 was the artifact); every number matched.",
      "sentinel" = "The Table 11 light range begins at the light-column low number; each heavier category begins at the previous category over; below the light low number the character is not encumbered, above the severe high number he cannot move. Table 12 reads normal/accelerated miles per half-day for a base 12-inch character, scaled down for slower ones.",
    },
  "consts" = { {
      "name" = "wemGpPerPound",
      "value" = 10,
      "comment" = "The standard conversion: a weight of 10 gp is one pound.",
    }, {
      "name" = "wemBulkNonFactor",
      "value" = 1,
      "comment" = "The rule of thumb: a non-bulky item rates its own weight in gp (equal to, or only slightly greater).",
    }, {
      "name" = "wemBulkyFactorMin",
      "value" = 2,
      "comment" = "A bulky object rates at least two times its weight.",
    }, {
      "name" = "wemBulkyFactorMax",
      "value" = 3,
      "comment" = "A bulky object rates two or three times its weight (the upper bound).",
    }, {
      "name" = "wemVeryBulkyFactor",
      "value" = 5,
      "comment" = "A very bulky object rates at least five times its weight.",
    }, {
      "name" = "wemEncRowCount",
      "value" = 14,
      "comment" = "The Table 11 strength-row count.",
    }, {
      "name" = "wemPctRowBase",
      "value" = 9,
      "comment" = "The first percentile row index in Table 11 (the 18/01-50 row).",
    }, {
      "name" = "wemTerrainClassCount",
      "value" = 3,
      "comment" = "The terrain classes for movement rate: normal, rugged, very rugged.",
    }, {
      "name" = "wemSnowRuggedMinIn",
      "value" = 5,
      "comment" = "Normal terrain under 5 to 10 inches of snow counts as rugged (the low bound).",
    }, {
      "name" = "wemSnowRuggedMaxIn",
      "value" = 10,
      "comment" = "Normal terrain under 5 to 10 inches of snow counts as rugged (the high bound).",
    }, {
      "name" = "wemSnowVRuggedNormalIn",
      "value" = 10,
      "comment" = "Normal terrain with more than 10 inches of snow counts as very rugged.",
    }, {
      "name" = "wemSnowVRuggedRuggedIn",
      "value" = 5,
      "comment" = "Rugged terrain with more than 5 inches of snow counts as very rugged.",
    }, {
      "name" = "wemRuggedStreamMinHrs",
      "value" = 3,
      "comment" = "Streams crossed one every 3-4 hours make the terrain rugged (the low bound).",
    }, {
      "name" = "wemRuggedStreamMaxHrs",
      "value" = 4,
      "comment" = "Streams crossed one every 3-4 hours make the terrain rugged (the high bound).",
    }, {
      "name" = "wemVRuggedStreamHrs",
      "value" = 2,
      "comment" = "Rivers or streams crossed one every 2 hours or less make the terrain very rugged.",
    }, {
      "name" = "wemMilesPerInchHalfDay",
      "value" = 1,
      "comment" = "Large-scale movement: each 1 inch of movement rate is that many miles per half-day.",
    }, {
      "name" = "wemHalfDayHours",
      "value" = 8,
      "comment" = "One half-day of movement is eight hours.",
    }, {
      "name" = "wemRestHoursMin",
      "value" = 1,
      "comment" = "A prolonged rest period is at least one hour.",
    }, {
      "name" = "wemOver8hNum",
      "value" = 3,
      "comment" = "Past eight hours without a prolonged rest: 3/4 of the normal maximum speed (numerator).",
    }, {
      "name" = "wemOver8hDen",
      "value" = 4,
      "comment" = "The past-eight-hours reduction denominator.",
    }, {
      "name" = "wemOver16hNum",
      "value" = 1,
      "comment" = "Past 16 hours without stopping to eat and rest: 1/3 of the normal maximum rate (numerator).",
    }, {
      "name" = "wemOver16hDen",
      "value" = 3,
      "comment" = "The past-16-hours reduction denominator.",
    }, {
      "name" = "wemT12RowCount",
      "value" = 5,
      "comment" = "The Table 12 encumbrance-category count.",
    }, {
      "name" = "wemT12BaseMove",
      "value" = 12,
      "comment" = "Table 12 assumes a base movement rate of 12 inches.",
    } },
  "bools" = { {
      "name" = "wemOneSetClothingFree",
      "value" = true,
      "comment" = "One set of normal, light clothing adds no encumbrance.",
    }, {
      "name" = "wemColdOuterwearCounts",
      "value" = true,
      "comment" = "Heavy and bulky cold-weather outerwear is not the free set of clothing.",
    }, {
      "name" = "wemSoleSmallItemFree",
      "value" = true,
      "comment" = "Thieves' picks and tools, or any similar small item, add no encumbrance when carried alone.",
    }, {
      "name" = "wemSmallComponentsFree",
      "value" = true,
      "comment" = "Material components for spells, when not large or bulky, add no encumbrance.",
    }, {
      "name" = "wemHelmetWithArmorFree",
      "value" = true,
      "comment" = "A helmet (but not a great helmet) worn with armor adds no encumbrance.",
    }, {
      "name" = "wemGreatHelmetCounts",
      "value" = true,
      "comment" = "A great helmet is not the free helmet.",
    }, {
      "name" = "wemBulkMayExceedWeight",
      "value" = true,
      "comment" = "The bulk of an object may matter more than its weight (the 20-pound sack of feathers).",
    }, {
      "name" = "wemEncValueDmRuling",
      "value" = true,
      "comment" = "The Dungeon Master frequently rules on the encumbrance value of objects.",
    }, {
      "name" = "wemDeviationKeepProportions",
      "value" = true,
      "comment" = "Any DM deviation must keep the movement rates and the encumbrance limits in proportion to one another.",
    }, {
      "name" = "wemBelowLightNotEncumbered",
      "value" = true,
      "comment" = "Below the light-column low number the character is not encumbered.",
    }, {
      "name" = "wemAboveSevereCannotMove",
      "value" = true,
      "comment" = "Above the severe-column high number a character cannot move, engage in combat or perform any other physical activity.",
    }, {
      "name" = "wemAboveSevereDmDamage",
      "value" = true,
      "comment" = "An overburdened character may, at the DM discretion, suffer damage.",
    }, {
      "name" = "wemConsistentPathIsNormal",
      "value" = true,
      "comment" = "A well-kept path or roadway through topographically consistent normal or rugged terrain counts as normal terrain.",
    }, {
      "name" = "wemPathInVRuggedIsRugged",
      "value" = true,
      "comment" = "A well-kept path or roadway through very rugged terrain counts as rugged.",
    }, {
      "name" = "wemLargeScaleAssumesLightRugged",
      "value" = true,
      "comment" = "The large-scale scale assumes a lightly encumbered character moving over rugged terrain.",
    }, {
      "name" = "wemT12ScaleForSlower",
      "value" = true,
      "comment" = "A slower base movement rate scales the Table 12 figures down accordingly.",
    }, {
      "name" = "wemAccMoveNeedsRest",
      "value" = true,
      "comment" = "The accelerated rate requires periodic rests to avoid fatigue; the rest stops are built into the figures.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 11: the encumbrance limits for characters",
      "tag" = "11",
      "count" = "wemEncRowCount",
      "cols" = { "wemEncLightMin", "wemEncLightMax", "wemEncModMax", "wemEncHvMax", "wemEncSevMax" },
      "col_default" = 0,
      "col_comments" = { "The light-column low number by strength row (below it: not encumbered).", "The light-column high number by strength row.", "The moderate-column high number by strength row (the range begins at the light high over).", "The heavy-column high number by strength row.", "The severe-column high number by strength row (above it: cannot move)." },
      "data" = { { 40, 100, 350, 700, 1150 }, { 50, 150, 450, 800, 1250 }, { 60, 200, 550, 900, 1350 }, { 90, 350, 700, 1050, 1500 }, { 120, 450, 800, 1150, 1600 }, { 140, 550, 900, 1250, 1700 }, { 160, 700, 1050, 1400, 1850 }, { 170, 850, 1200, 1550, 2000 }, { 180, 1000, 1400, 1700, 2250 }, { 190, 1100, 1450, 1750, 2500 }, { 200, 1200, 1500, 1800, 2750 }, { 210, 1300, 1600, 2000, 3000 }, { 220, 1400, 1700, 2200, 3500 }, { 250, 1500, 1900, 2400, 4500 } },
      "audit_comment" = "the Table 11 grid: the 14 strength rows x the light/moderate/heavy/severe gp limits, rows ordered 3, 4-5, 6-7, 8-11, 12-13, 14-15, 16, 17, 18, 18/01-50, 18/51-75, 18/76-90, 18/91-99, 18/00",
    }, {
      "name" = "Table 12: the character movement on foot",
      "tag" = "12",
      "count" = "wemT12RowCount",
      "cols" = { "wemMvNormNorm", "wemMvAccelNorm", "wemMvNormRug", "wemMvAccelRug", "wemMvNormVr", "wemMvAccelVr" },
      "col_default" = 0,
      "col_comments" = { "The normal maximum miles per half-day, normal terrain, by encumbrance row (none, light, moderate, heavy, severe).", "The accelerated miles per half-day, normal terrain.", "The normal maximum miles per half-day, rugged terrain.", "The accelerated miles per half-day, rugged terrain.", "The normal maximum miles per half-day, very rugged terrain.", "The accelerated miles per half-day, very rugged terrain." },
      "data" = { { 15, 18, 12, 16, 8, 10 }, { 12, 16, 12, 15, 6, 9 }, { 10, 12, 9, 11, 4, 6 }, { 7, 10, 6, 8, 3, 5 }, { 5, 7, 3, 5, 2, 3 } },
      "audit_comment" = "the Table 12 grid: the encumbrance rows (none, light, moderate, heavy, severe) x the normal and accelerated rates over normal, rugged and very rugged terrain",
    } },
  "chains" = { {
      "name" = "wemStrRowFor",
      "arg" = "s",
      "limits" = { 3, 5, 7, 11, 13, 15, 16, 17 },
      "tail" = 8,
      "comment" = "The plain-strength row dispatch for Table 11: 3 -> 0, 4-5 -> 1, 6-7 -> 2, 8-11 -> 3, 12-13 -> 4, 14-15 -> 5, 16 -> 6, 17 -> 7, 18 -> 8; a percentile strength reads the percentile rows instead (wemPctRowFor plus wemPctRowBase).",
    }, {
      "name" = "wemPctRowFor",
      "arg" = "p",
      "limits" = { 50, 75, 90, 99 },
      "tail" = 4,
      "comment" = "The percentile-row offset within Table 11: 18/01-50 -> 0, 18/51-75 -> 1, 18/76-90 -> 2, 18/91-99 -> 3, 18/00 (read the percentile as 100) -> 4.",
    } },
  "examples" = { {
      "expr" = "m['wemMilesPerInchHalfDay']() * 12 != 12",
      "note" = "the worked example: a 12-inch rate covers 12 miles in the first half-day",
    }, {
      "expr" = "m['wemHalfDayHours']() * 3 / 2 != 12",
      "note" = "the 1.5 miles per hour for any span under the half-day (3 miles every 2 hours)",
    }, {
      "expr" = "12 * m['wemOver8hNum']() / m['wemOver8hDen']() != 9",
      "note" = "the second eight hours at 3/4 rate: 9 miles",
    }, {
      "expr" = "m['wemMilesPerInchHalfDay']() * 12 + 12 * m['wemOver8hNum']() / m['wemOver8hDen']() != 21",
      "note" = "16 hours of continual movement: 21 miles",
    }, {
      "expr" = "12 + 12 * m['wemOver8hNum']() / m['wemOver8hDen']() + 12 * m['wemOver16hNum']() / m['wemOver16hDen']() != 25",
      "note" = "24 hours without rest: 25 miles",
    }, {
      "expr" = "m['wemMvAccelNorm'](1) != 16",
      "note" = "the light-encumbered, normal-terrain accelerated rate: 16 miles in the first eight hours",
    }, {
      "expr" = "m['wemEncLightMin'](m['wemStrRowFor'](8)) != 90",
      "note" = "strength 8 reads the 8-11 row: the light band begins at 90 gp",
    }, {
      "expr" = "m['wemEncSevMax'](m['wemPctRowFor'](100) + m['wemPctRowBase']()) != 4500",
      "note" = "the percentile 00 (read as 100) reads the 18/00 row: severe tops at 4500 gp",
    } },
  "audit" = {
      "label" = "R432 WSG encumbrance pin audit",
      "comment" = "The encumbrance and movement slice pins Table 11 (the 14 strength rows x the Light/Moderate/Heavy/Severe gp limits), Table 12 (the encumbrance category x the terrain class, the normal and the accelerated rates), the bulk rule-of-thumb, the terrain definitions and the large-scale overland movement rules (rules/wsgencum.h, prefix wem); census 356 -> 357.",
    },
}
