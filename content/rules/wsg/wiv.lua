-- wiv: promoted from tools/spec_r483.json (the R483: the WSG INFRAVISION and TABLE 41 slice, printed p. 73 - the second vision-and-visibility round, a TABLE round: the heat-vision definition with the 60/30/120 infravisual ranges, and the six-condition four-light-level outdoor range of normal vision grid with its size M/L/S doubling and halving semantics, the long-range concentration assumption, the prone-target and three-foot-grass hiding rules, the daylight dual-scan gaze discipline and the moonlight/darkness footing discipline.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 483,
  "prefix" = "wiv",
  "banner" = {
      "title" = "R483: the WSG INFRAVISION and TABLE 41 slice, printed p. 73 - the second vision-and-visibility round, a TABLE round: the heat-vision definition with the 60/30/120 infravisual ranges, and the six-condition four-light-level outdoor range of normal vision grid with its size M/L/S doubling and halving semantics, the long-range concentration assumption, the prone-target and three-foot-grass hiding rules, the daylight dual-scan gaze discipline and the moonlight/darkness footing discipline.",
      "provenance" = "The settle: two-way clean on the first pass - the tesseract full-text read, the pdfy layout read and the tsv coordinate read agree on every number of the page (all 24 grid cells, the 60/30/120 infravision ranges, the double/halve factors), with the tsv confirming the two-line heavy-snow and heavy-fog rows cell by cell; the infravision paragraph is cut mid-word at the page bottom (In-), its continuation belonging to p. 74 with the ultravision round. No contested cells, no vision reads needed.",
      "sentinel" = "Bounds held: moonlight never reads below darkness in any condition, blowing sand is the one condition whose daylight equals twilight, and the deep-race range is exactly double the standard range which is exactly double the halfling range.",
    },
  "consts" = { {
      "name" = "wivConditionCount",
      "value" = 6,
      "comment" = "six weather and obstruction conditions in Table 41",
    }, {
      "name" = "wivLightLevelCount",
      "value" = 4,
      "comment" = "four light levels: daylight, twilight, moonlight, darkness",
    }, {
      "name" = "wivSizeLDoubleFactor",
      "value" = 2,
      "comment" = "double the size M range for a size L object",
    }, {
      "name" = "wivSizeSHalfFactor",
      "value" = 2,
      "comment" = "halve the size M range for a size S object",
    }, {
      "name" = "wivInfravisionRangeYards",
      "value" = 60,
      "comment" = "most nonhuman player characters see this far (outdoor scale)",
    }, {
      "name" = "wivHalflingRangeYards",
      "value" = 30,
      "comment" = "halflings other than pure-blooded Stouts: 30 yards",
    }, {
      "name" = "wivDeepRangeYards",
      "value" = 120,
      "comment" = "drow, duergar and deep gnomes: 120 yards",
    } },
  "bools" = { {
      "name" = "wivYardsUnits",
      "value" = true,
      "comment" = "the Table 41 entries are expressed in yards",
    }, {
      "name" = "wivSizeMStandsOut",
      "value" = true,
      "comment" = "the given range is the distance at which a viewer discerns a size M object that stands out from the terrain and its surroundings",
    }, {
      "name" = "wivAssumesLongRangeFocus",
      "value" = true,
      "comment" = "seeing at the given range assumes the viewer is concentrating on long-range vision",
    }, {
      "name" = "wivTargetNotConcealed",
      "value" = true,
      "comment" = "the target, if one exists, is not concealed or trying to keep from being seen",
    }, {
      "name" = "wivLyingDownReduces",
      "value" = true,
      "comment" = "a target lying down on a flat featureless plain is greatly harder to spot from long distance",
    }, {
      "name" = "wivGrassHidesUntilClose",
      "value" = true,
      "comment" = "in three-foot-high grass a prone target is effectively invisible until the viewer is very close",
    }, {
      "name" = "wivDaylightDualScan",
      "value" = true,
      "comment" = "in daylight or twilight a character can employ long-range and short-range normal vision at the same time",
    }, {
      "name" = "wivGazeShiftEveryFewSeconds",
      "value" = true,
      "comment" = "the dual scan works by shifting his gaze every few seconds",
    }, {
      "name" = "wivFullSpeedDualScan",
      "value" = true,
      "comment" = "in sufficient illumination a character can move at full normal speed and stay aware of features at both ranges while keeping his gaze shifting",
    }, {
      "name" = "wivDarkScanDegrades",
      "value" = true,
      "comment" = "in moonlight or darkness it is much harder to keep moving and stay cognizant of short-range and long-range objects at once",
    }, {
      "name" = "wivDarkFootingFirst",
      "value" = true,
      "comment" = "a lone character on the move in moonlight or darkness is usually better off watching what he is walking on",
    }, {
      "name" = "wivLookoutDutySplit",
      "value" = true,
      "comment" = "two or more travelers best divide lookout duty: one peers far ahead, another watches the ground a few paces ahead",
    }, {
      "name" = "wivStopAndPeerSafest",
      "value" = true,
      "comment" = "the safest way to scan the distance in poor illumination is to first come to a stop and then peer ahead",
    }, {
      "name" = "wivMovingHazardUnseen",
      "value" = true,
      "comment" = "even stopped and peering, a nearby hazard moving toward him silent and unseen is not ruled out",
    }, {
      "name" = "wivHeatVisionDefinition",
      "value" = true,
      "comment" = "infravision, or heat vision, is the ability to see the shapes of objects by sensing radiation in the infrared spectrum",
    }, {
      "name" = "wivAllNonhumanHaveInfravision",
      "value" = true,
      "comment" = "all nonhuman player characters have infravision",
    }, {
      "name" = "wivMostOutTo60Yards",
      "value" = true,
      "comment" = "most of them have it out to a range of 60 yards (outdoor scale)",
    }, {
      "name" = "wivHalfling30UnlessStout",
      "value" = true,
      "comment" = "halflings other than pure-blooded Stouts have an infravisual range of 30 yards",
    }, {
      "name" = "wivDeepRaces120",
      "value" = true,
      "comment" = "drow, duergar and deep gnomes have infravision out to 120 yards",
    }, {
      "name" = "wivOutdoorScaleNote",
      "value" = true,
      "comment" = "the infravision ranges are outdoor scale, like the Table 41 ranges",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "wivRangeGrid",
      "tag" = "41",
      "count" = "wivConditionCount",
      "cols" = { "wivDaylightYards", "wivTwilightYards", "wivMoonlightYards", "wivDarknessYards" },
      "col_comments" = { "Table 41 outdoor range in yards: daylight", "Table 41 outdoor range in yards: twilight", "Table 41 outdoor range in yards: moonlight", "Table 41 outdoor range in yards: darkness" },
      "col_default" = 0,
      "data" = { { 500, 300, 50, 25 }, { 400, 250, 50, 25 }, { 150, 100, 25, 15 }, { 50, 30, 15, 10 }, { 35, 25, 10, 5 }, { 20, 20, 10, 5 } },
    } },
  "chains" = {},
  "examples" = { {
      "note" = "clear daylight is 500 yards, the R482 effective range; doubled for size L it is the 1000 floor",
      "expr" = "m['wivDaylightYards'](0) != 500 or m['wivDaylightYards'](0) * m['wivSizeLDoubleFactor']() != 1000",
    }, {
      "note" = "clear daylight halved for size S is the 250 size S distance",
      "expr" = "m['wivDaylightYards'](0) / m['wivSizeSHalfFactor']() != 250",
    }, {
      "note" = "moonlight never below darkness, and blowing sand twilight EQUALS daylight (no strict drop)",
      "expr" = "m['wivMoonlightYards'](0) < m['wivDarknessYards'](0) or m['wivTwilightYards'](5) < m['wivDaylightYards'](5)",
    }, {
      "note" = "the deep-race range doubles the standard range, which doubles the halfling range",
      "expr" = "m['wivDeepRangeYards']() != 2 * m['wivInfravisionRangeYards']() or m['wivInfravisionRangeYards']() != 2 * m['wivHalflingRangeYards']()",
    } },
  "audit" = {
      "label" = "R483 WSG infravision pin audit",
      "comment" = "The infravision and Table 41 rules: infravision, or heat vision, is the ability to see the shapes of objects by sensing radiation in the infrared spectrum; all nonhuman player characters have it, most out to 60 yards (outdoor scale); halflings other than pure-blooded Stouts see 30 yards; drow, duergar and deep gnomes see 120. Table 41 gives the outdoor range of normal vision in yards for six conditions across four light levels: clear 500/300/50/25; overcast 400/250/50/25; moderate fog 150/100/25/15; heavy fog, rain or snow 50/30/15/10; heavy snow with wind 35/25/10/5; blowing sand or dust 20/20/10/5. The given range is the distance at which a viewer discerns a size M object that stands out from the terrain; double it for size L, halve it for size S. The range assumes long-range concentration and a target that is not concealed: the orc lying down on the plain is greatly harder to spot, and prone in three-foot grass it is effectively invisible until the viewer is very close. In daylight or twilight a character can scan long and short range at once by shifting his gaze every few seconds, even at full speed; in moonlight or darkness that fails - a moving character may step into a crevasse he just looked at, so a lone traveler watches his footing, a group splits lookout duty, and stopping to peer is safest but still no guard against a nearby silent moving hazard.",
    },
}
