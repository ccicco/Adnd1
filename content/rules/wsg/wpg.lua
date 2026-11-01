-- wpg: promoted from tools/spec_r458.json (the The WSG PORTAGING, R458: it is not unusual for areas of the wilderness to be dotted with small lakes or streams separated from one another by short expanses of land, and characters may find it desirable or necessary to portage their vessels (carry them overland) from one body of water to another rather than leave them behind. As with all encumbrance values, the ones given for watercraft account for the bulkiness of the vessel as well as its actual weight. If a character is able to support the listed amount without becoming severely encumbered, and if the vessel is smaller than a large rowboat, he can portage the vessel by himself. Severely encumbered characters cannot portage, or help to portage, a vessel. A large rowboat or a small barge requires at least two characters to share its encumbrance, and a large barge must be portaged by at least four characters. No vessel can be portaged by more than twice the minimum number needed to carry it - a third character is of no use in an attempt to portage a small canoe; despite his presence, the canoe must be able to be carried by the other two characters, or it cannot be portaged. Any character portaging or helping to portage a vessel can move no faster than 3 inches of movement (3 miles in eight hours, or 30 feet per round), regardless of terrain or his overall encumbrance status.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 458,
  "prefix" = "wpg",
  "banner" = {
      "title" = "The WSG PORTAGING, R458: it is not unusual for areas of the wilderness to be dotted with small lakes or streams separated from one another by short expanses of land, and characters may find it desirable or necessary to portage their vessels (carry them overland) from one body of water to another rather than leave them behind. As with all encumbrance values, the ones given for watercraft account for the bulkiness of the vessel as well as its actual weight. If a character is able to support the listed amount without becoming severely encumbered, and if the vessel is smaller than a large rowboat, he can portage the vessel by himself. Severely encumbered characters cannot portage, or help to portage, a vessel. A large rowboat or a small barge requires at least two characters to share its encumbrance, and a large barge must be portaged by at least four characters. No vessel can be portaged by more than twice the minimum number needed to carry it - a third character is of no use in an attempt to portage a small canoe; despite his presence, the canoe must be able to be carried by the other two characters, or it cannot be portaged. Any character portaging or helping to portage a vessel can move no faster than 3 inches of movement (3 miles in eight hours, or 30 feet per round), regardless of terrain or his overall encumbrance status.",
      "provenance" = "the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 45-46 (the section spans the page break); the user own copy OCR (pages 46-47) cross-checked against the archive djvu word layer (Guide_0045/0046) - the prose reads clean two-way, with only the usual page-break garble in the djvu (the solo- portage clause, which the user OCR reads whole and the continuation text confirms); NO eye-reads needed (a pure-prose section, no printed grid).",
    },
  "consts" = { {
      "name" = "wpgVesselCount",
      "value" = 8,
      "comment" = "The same eight vessels as Tables 25 and 26: kayak, small canoe, small rowboat, coracle, large canoe, large rowboat, small barge and large barge.",
    }, {
      "name" = "wpgMaxCrewMultiplier",
      "value" = 2,
      "comment" = "No vessel can be portaged by more than twice the minimum number needed to carry it.",
    }, {
      "name" = "wpgLargeBargeMinCrew",
      "value" = 4,
      "comment" = "A large barge must be portaged by at least four characters.",
    }, {
      "name" = "wpgPortageMoveInches",
      "value" = 3,
      "comment" = "Any character portaging or helping to portage a vessel can move no faster than 3 inches of movement.",
    }, {
      "name" = "wpgPortageMilesPerHalfDay",
      "value" = 3,
      "comment" = "The portage move rate is 3 miles in eight hours on the large scale.",
    }, {
      "name" = "wpgPortageFeetPerRound",
      "value" = 30,
      "comment" = "The portage move rate is 30 feet per round on the small scale.",
    } },
  "bools" = { {
      "name" = "wpgSoloBelowLargeRowboat",
      "value" = true,
      "comment" = "A vessel smaller than a large rowboat can be portaged by a single character.",
    }, {
      "name" = "wpgSoloNeedsNoSevereEncumbrance",
      "value" = true,
      "comment" = "The solo porter must be able to support the listed encumbrance amount without becoming severely encumbered.",
    }, {
      "name" = "wpgSevereBlocksPortageAndHelp",
      "value" = true,
      "comment" = "Severely encumbered characters cannot portage, or help to portage, a vessel.",
    }, {
      "name" = "wpgCrewSharesEncumbrance",
      "value" = true,
      "comment" = "The multiple porters of a larger vessel share its encumbrance between them.",
    }, {
      "name" = "wpgCrewCappedAtTwiceMin",
      "value" = true,
      "comment" = "No vessel can be portaged by more than twice its minimum crew - the crew grid hard-codes the cap per vessel.",
    }, {
      "name" = "wpgBeyondMaxIsUseless",
      "value" = true,
      "comment" = "A character beyond the maximum crew is of no use - a third character cannot help two others portage a small canoe.",
    }, {
      "name" = "wpgMoveCapIgnoresTerrain",
      "value" = true,
      "comment" = "The 3-inch portage move rate holds regardless of terrain.",
    }, {
      "name" = "wpgMoveCapIgnoresEncumbrance",
      "value" = true,
      "comment" = "The 3-inch portage move rate holds regardless of the overall encumbrance status.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "the portage crew grid",
      "tag" = "28",
      "count" = "wpgVesselCount",
      "col_default" = 0,
      "audit_comment" = "the portage-crew grid: the eight vessels (kayak, small canoe, small rowboat, coracle, large canoe, large rowboat, small barge, large barge) with the minimum portage crew and the maximum (twice the minimum)",
      "cols" = { "wpgMinCrew", "wpgMaxCrew" },
      "col_comments" = { "the minimum portage crew - one below the large rowboat, two for the large rowboat and small barge, four for the large barge", "the maximum portage crew - twice the minimum: two, two, two, two, two, four, four and eight" },
      "data" = { { 1, 2 }, { 1, 2 }, { 1, 2 }, { 1, 2 }, { 1, 2 }, { 2, 4 }, { 2, 4 }, { 4, 8 } },
      "row_labels" = { "kayak", "small canoe", "small rowboat", "coracle", "large canoe", "large rowboat", "small barge", "large barge" },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['wpgMinCrew'](0) != 1 or m['wpgMinCrew'](1) != 1 or m['wpgMinCrew'](2) != 1 or m['wpgMinCrew'](3) != 1 or m['wpgMinCrew'](4) != 1",
      "note" = "the solo group: the kayak, the small canoe, the small rowboat, the coracle and the large canoe are all smaller than a large rowboat and portage with a single character",
    }, {
      "expr" = "m['wpgMinCrew'](5) != 2 or m['wpgMinCrew'](6) != 2 or m['wpgMinCrew'](7) != 4 or m['wpgMinCrew'](7) != 2 * m['wpgMinCrew'](5)",
      "note" = "the crew minimums: the large rowboat and the small barge need two porters, the large barge four - twice the large-rowboat minimum",
    }, {
      "expr" = "m['wpgMaxCrew'](0) != 2 or m['wpgMaxCrew'](5) != 4 or m['wpgMaxCrew'](6) != 4 or m['wpgMaxCrew'](7) != 8",
      "note" = "the crew maximums: twice the minimum throughout - two carriers for a small canoe, four for a large rowboat or small barge, eight for a large barge",
    }, {
      "expr" = "m['wpgMaxCrew'](0) != 2 * m['wpgMinCrew'](0) or m['wpgMaxCrew'](2) != 2 * m['wpgMinCrew'](2) or m['wpgMaxCrew'](7) != 2 * m['wpgMinCrew'](7) or m['wpgMaxCrewMultiplier']() != 2",
      "note" = "the twice-minimum law holds row by row - the maximum crew is exactly the minimum times the multiplier constant",
    }, {
      "expr" = "m['wpgPortageMoveInches']() != 3 or m['wpgPortageMilesPerHalfDay']() != 3 or m['wpgPortageFeetPerRound']() != 30 or m['wpgPortageFeetPerRound']() != 10 * m['wpgPortageMoveInches']()",
      "note" = "the portage move rate: 3 inches of movement, 3 miles in eight hours, 30 feet per round - the feet figure is ten times the inches",
    }, {
      "expr" = "m['wpgMinCrew'](7) != m['wpgLargeBargeMinCrew']() or m['wpgMaxCrew'](7) != m['wpgLargeBargeMinCrew']() * 2",
      "note" = "the large barge cross-tie: its grid minimum matches the four-character crew constant and its maximum is twice that",
    } },
  "audit" = {
      "label" = "R458 WSG portaging pin audit",
      "comment" = "The portaging slice pins the solo-portage gate (a vessel smaller than a large rowboat carried by one character able to support its encumbrance without becoming severely encumbered), the severe-encumbrance bar on portaging or helping, the portage-crew minimums (two for the large rowboat and the small barge, four for the large barge) with the maximum of twice the minimum, the beyond-max futility (the third small-canoe carrier), and the 3-inch portage move rate - 3 miles in eight hours, 30 feet per round, regardless of terrain or overall encumbrance status (rules/wsgportage.h, prefix wpg); census 382 -> 383.",
    },
}
