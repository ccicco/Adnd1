-- wns: promoted from tools/spec_r471.json (the R471: the WSG NATURAL SHELTERS slice with TABLE 35 - the arc opener (comfortable manmade structures not conveniently appearing whenever characters need shelter and warmth; through well-mapped territory the route plannable to arrive at marked natural shelters, through unfamiliar terrain the lucky find: a small cave on a rocky slope, a thick grove at the edge of a grassy plain, a pile of dead wood in a swamp), the two major factors (the terrain and the time of year), the Table 35 grid (the percentage chance of finding a natural shelter or easily obtainable construction materials: Desert constant 20 across the seasons, Forest 90/100/100/100, Hills 40/60/70/60, Mountains constant 40, Plains 30/40/40/30, Swamp 40/50/50/40), the check discipline (the DM checks whenever characters indicate they are looking; a failed check allows further checks at three-turn intervals while they keep moving, until shelter is found or they stop and camp unsheltered), the forest construction rules (an evergreen forest scrounges long straight wood and boughs easily; a forest of normal or light density cuts boughs or branches to lay across a grid of poles for a roof and, properly positioned, protection from wind and precipitation; pack animals may not enter closely packed vegetation without a path; it takes 3-8 turns - 1d6+2 - for a single character to obtain the materials, minus 2 turns per additional helper down to a minimum of 3, then another 6 turns to lash the poles and bind the shingles, minus 1 turn per helper to a maximum of two helpers, the construction time halved with a rope use proficiency character among the workers), the terrain notes (the desert has no usable vegetation but occasional surface irregularities - large rocks, small crevasses, a steeply sloping sand dune - sheltering at least one side; hills full of irregular windbreak terrain with sturdy vegetation abundant in spring, summer and autumn; mountains rough and rocky with little or no vegetation, any vegetation treated as hills or forest, the mountain entries modeling natural features - a cave, alcove or chimney between rock faces - large enough to contain the party where the wind cannot get inside; plains generally flat, a small gully two or three feet deep getting a character out of the wind but the worst shelter in heavy rain, windbreak materials scavengable where vegetation is more substantial than grasses and knee-high scrub, the material time 7-12 turns in non-lush terrain vs the 3-8 forest; the swamp usually scavengeable with debris piles, fallen trees or similar features serving as a shelter or its foundation) and the shelter-quality guidelines (many small pieces of vegetation: poor, at best adequate; few large sturdy pieces: adequate or perhaps good; the side of a large rock facing away from the wind: good wind protection but only adequate or poor against precipitation - the guidelines seam mid-sentence onto p. 62 at the cave sentence), printed p. 61.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 471,
  "prefix" = "wns",
  "banner" = {
      "title" = "R471: the WSG NATURAL SHELTERS slice with TABLE 35 - the arc opener (comfortable manmade structures not conveniently appearing whenever characters need shelter and warmth; through well-mapped territory the route plannable to arrive at marked natural shelters, through unfamiliar terrain the lucky find: a small cave on a rocky slope, a thick grove at the edge of a grassy plain, a pile of dead wood in a swamp), the two major factors (the terrain and the time of year), the Table 35 grid (the percentage chance of finding a natural shelter or easily obtainable construction materials: Desert constant 20 across the seasons, Forest 90/100/100/100, Hills 40/60/70/60, Mountains constant 40, Plains 30/40/40/30, Swamp 40/50/50/40), the check discipline (the DM checks whenever characters indicate they are looking; a failed check allows further checks at three-turn intervals while they keep moving, until shelter is found or they stop and camp unsheltered), the forest construction rules (an evergreen forest scrounges long straight wood and boughs easily; a forest of normal or light density cuts boughs or branches to lay across a grid of poles for a roof and, properly positioned, protection from wind and precipitation; pack animals may not enter closely packed vegetation without a path; it takes 3-8 turns - 1d6+2 - for a single character to obtain the materials, minus 2 turns per additional helper down to a minimum of 3, then another 6 turns to lash the poles and bind the shingles, minus 1 turn per helper to a maximum of two helpers, the construction time halved with a rope use proficiency character among the workers), the terrain notes (the desert has no usable vegetation but occasional surface irregularities - large rocks, small crevasses, a steeply sloping sand dune - sheltering at least one side; hills full of irregular windbreak terrain with sturdy vegetation abundant in spring, summer and autumn; mountains rough and rocky with little or no vegetation, any vegetation treated as hills or forest, the mountain entries modeling natural features - a cave, alcove or chimney between rock faces - large enough to contain the party where the wind cannot get inside; plains generally flat, a small gully two or three feet deep getting a character out of the wind but the worst shelter in heavy rain, windbreak materials scavengable where vegetation is more substantial than grasses and knee-high scrub, the material time 7-12 turns in non-lush terrain vs the 3-8 forest; the swamp usually scavengeable with debris piles, fallen trees or similar features serving as a shelter or its foundation) and the shelter-quality guidelines (many small pieces of vegetation: poor, at best adequate; few large sturdy pieces: adequate or perhaps good; the side of a large rock facing away from the wind: good wind protection but only adequate or poor against precipitation - the guidelines seam mid-sentence onto p. 62 at the cave sentence), printed p. 61.",
      "provenance" = "Ground truth two-way: the user-run Termux tesseract text of printed p. 61 (the --psm 4 run) vs a VISION READ of the uploaded page image (pg61-000.png). The pdf text layer garbles the Table 35 grid badly (dropping the Forest, Hills and Mountains rows entirely and reading 4c for the Plains autumn 40) and serves as the prose-only third reader. The tesseract and vision reads AGREE ON ALL 24 TABLE CELLS: Desert 20/20/20/20, Forest 90/100/100/100, Hills 40/60/70/60, Mountains 40/40/40/40, Plains 30/40/40/30, Swamp 40/50/50/40 - no contested cells, no physical-page reads. The prose numbers agree across tesseract and the pdf layer: the 1d6+2 dice, the minus-2 helper reduction with the 3-turn floor, the 6-turn lashing with the minus-1 helper reduction and the two-helper cap, the rope-use halving, the 7-12 plains ladder, the three-turn check interval and the two-or-three-foot gully depth. The section prose ends mid-sentence at the page foot (A cave in the face of a mountain...), the tail running onto p. 62 with the portable-shelters material.",
      "sentinel" = "A TABLE round after three prose rounds: the 24-cell Table 35 grid pins as four season columns, the construction ladders and the terrain notes as consts and bools, every one audit-verified against the model.",
    },
  "consts" = { {
      "name" = "wnsTerrainCount",
      "value" = 6,
      "comment" = "the Table 35 terrain row count: desert, forest, hills, mountains, plains, swamp",
    }, {
      "name" = "wnsForestMatsMinTurns",
      "value" = 3,
      "comment" = "a single character obtains simple-shelter materials in a forest in 3-8 turns (1d6+2): the dice floor",
    }, {
      "name" = "wnsForestMatsMaxTurns",
      "value" = 8,
      "comment" = "the forest material time: the dice ceiling (6+2)",
    }, {
      "name" = "wnsHelperMatsReduction",
      "value" = 2,
      "comment" = "minus 2 turns of material time for each additional character assisting in the work",
    }, {
      "name" = "wnsMatsTimeFloor",
      "value" = 3,
      "comment" = "the helper reduction bottoms out: a minimum of 3 turns of material time",
    }, {
      "name" = "wnsLashBaseTurns",
      "value" = 6,
      "comment" = "another 6 turns for a character to lash together the poles and bind the shingles to the grid",
    }, {
      "name" = "wnsHelperLashReduction",
      "value" = 1,
      "comment" = "minus 1 turn of lashing for each additional character assisting",
    }, {
      "name" = "wnsMaxLashHelpers",
      "value" = 2,
      "comment" = "the lashing helper reduction caps at a maximum of two helpers",
    }, {
      "name" = "wnsPlainsMatsMinTurns",
      "value" = 7,
      "comment" = "in non-lush plains terrain a single character needs 7-12 turns for enough materials (vs the 3-8 forest): the floor",
    }, {
      "name" = "wnsPlainsMatsMaxTurns",
      "value" = 12,
      "comment" = "the plains material time: the ceiling",
    }, {
      "name" = "wnsRecheckIntervalTurns",
      "value" = 3,
      "comment" = "after a failed shelter check with the party still moving, further checks at intervals of three turns",
    } },
  "bools" = { {
      "name" = "wnsTerrainSeasonMajor",
      "value" = true,
      "comment" = "the terrain and the time of year are the major factors in determining the chance to locate a natural shelter or construct one from natural materials",
    }, {
      "name" = "wnsCheckOnLooking",
      "value" = true,
      "comment" = "the Dungeon Master should check whenever characters indicate that they are looking for shelter; failed checks with the party still moving allow rechecks until shelter is found or they stop and camp unsheltered",
    }, {
      "name" = "wnsForestEasyMaterials",
      "value" = true,
      "comment" = "in an evergreen forest it is fairly easy to scrounge long, straight pieces of wood and boughs to make a windbreak; forest areas are replete with natural shelter",
    }, {
      "name" = "wnsPlainMtnImpossible",
      "value" = true,
      "comment" = "on a flat plain or in a mountainous area at high elevation it is practically impossible to find such materials: characters hope for a natural feature - a shallow gully, a small cave beneath a rock outcropping",
    }, {
      "name" = "wnsBoughRoofShelter",
      "value" = true,
      "comment" = "in a forest of normal or even light density, boughs or branches cut and laid across a grid of poles give characters a roof and, properly positioned, protection from the full force of wind and precipitation",
    }, {
      "name" = "wnsPackAnimalsNeedPath",
      "value" = true,
      "comment" = "pack animals may not be willing or able to enter an area of closely packed vegetation unless there is a path into it or through it that they can negotiate",
    }, {
      "name" = "wnsRopeUseHalvesTime",
      "value" = true,
      "comment" = "the construction time is halved if a character with proficiency in rope use is among those doing the work",
    }, {
      "name" = "wnsDesertSurfaceIrregularities",
      "value" = true,
      "comment" = "desert terrain has no usable vegetation, but occasional surface irregularities - large rocks, small crevasses, a steeply sloping sand dune - provide shelter on at least one side",
    }, {
      "name" = "wnsHillsWindbreak",
      "value" = true,
      "comment" = "hills are full of irregular terrain that can serve as a simple windbreak; during spring, summer and autumn thick sturdy vegetation is fairly abundant for a greenery windbreak just as in a forest",
    }, {
      "name" = "wnsMountainVegetationReading",
      "value" = true,
      "comment" = "mountains are rough, rocky areas with little or no vegetation; any existing mountain vegetation is treated as hills or forest for the find chance, and the mountain table entries model natural features - a cave, alcove or chimney between two rock faces - large enough to contain the party and located where the wind cannot get inside",
    }, {
      "name" = "wnsPlainsGully",
      "value" = true,
      "comment" = "plains are generally flat but not necessarily featureless: a small gully, two or three feet deep, gets a character out of the wind - but a gully is the worst possible shelter in very heavy rain",
    }, {
      "name" = "wnsPlainsScavengeWindbreak",
      "value" = true,
      "comment" = "if a plain has vegetation more substantial than grasses and knee-high scrub brush, characters may scavenge enough branches and greenery for a windbreak (in non-lush terrain the material time is 7-12 turns vs the 3-8 forest)",
    }, {
      "name" = "wnsSwampDebrisShelter",
      "value" = true,
      "comment" = "swamp areas usually have scavengeable vegetation, and it is not too unlikely to come across a pile of debris, a fallen tree or a similar terrain feature that serves as a shelter or the foundation for one",
    }, {
      "name" = "wnsQualityManySmallPoor",
      "value" = true,
      "comment" = "a natural shelter constructed from many small pieces of vegetation is usually a poor shelter, at best adequate",
    }, {
      "name" = "wnsQualityFewLargeGood",
      "value" = true,
      "comment" = "a shelter made from relatively few pieces of large, sturdy vegetation is adequate or perhaps good",
    }, {
      "name" = "wnsRockSideWindGood",
      "value" = true,
      "comment" = "the side of a large rock facing away from the wind offers good protection from the wind, but only adequate or poor protection from precipitation",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "wnsFindShelter",
      "tag" = "35",
      "count" = "wnsTerrainCount",
      "cols" = { "wnsWinter", "wnsSpring", "wnsSummer", "wnsAutumn" },
      "col_default" = 0,
      "col_comments" = { "the Table 35 winter find pct", "the Table 35 spring find pct", "the Table 35 summer find pct", "the Table 35 autumn find pct" },
      "row_comments" = { "the desert row", "the forest row", "the hills row", "the mountains row", "the plains row", "the swamp row" },
      "data" = { { 20, 20, 20, 20 }, { 90, 100, 100, 100 }, { 40, 60, 70, 60 }, { 40, 40, 40, 40 }, { 30, 40, 40, 30 }, { 40, 50, 50, 40 } },
      "audit_comment" = "Table 35: chance of finding natural shelter, the six-terrain by four-season percentage grid, printed p. 61",
      "sentinel" = 100,
      "sentinel_census" = { 0, 1, 1, 1 },
    } },
  "chains" = {},
  "examples" = { {
      "note" = "the forest material ladder: 3-8 turns (1d6+2)",
      "expr" = "m['wnsForestMatsMinTurns']() != 3 or m['wnsForestMatsMaxTurns']() != 8 or m['wnsForestMatsMinTurns']() >= m['wnsForestMatsMaxTurns']()",
    }, {
      "note" = "the helper economics: the 2-turn material reduction with the 3-turn floor, the 1-turn lash reduction with the two-helper cap",
      "expr" = "m['wnsHelperMatsReduction']() != 2 or m['wnsMatsTimeFloor']() != 3 or m['wnsHelperLashReduction']() != 1 or m['wnsMaxLashHelpers']() != 2",
    }, {
      "note" = "the plains ladder: 7-12 turns, above the forest band on both ends",
      "expr" = "m['wnsPlainsMatsMinTurns']() != 7 or m['wnsPlainsMatsMaxTurns']() != 12 or m['wnsPlainsMatsMinTurns']() <= m['wnsForestMatsMinTurns']() or m['wnsPlainsMatsMaxTurns']() <= m['wnsForestMatsMaxTurns']()",
    }, {
      "note" = "the check discipline: rechecks every 3 turns",
      "expr" = "m['wnsRecheckIntervalTurns']() != 3",
    }, {
      "note" = "the construction mechanics: the bough-roof shelter, the pack-animal path requirement and the rope-use halving",
      "expr" = "m['wnsBoughRoofShelter']() != 1 or m['wnsPackAnimalsNeedPath']() != 1 or m['wnsRopeUseHalvesTime']() != 1",
    }, {
      "note" = "the terrain notes: the desert irregularities, the hills windbreak, the mountain reading and the swamp debris",
      "expr" = "m['wnsDesertSurfaceIrregularities']() != 1 or m['wnsHillsWindbreak']() != 1 or m['wnsMountainVegetationReading']() != 1 or m['wnsSwampDebrisShelter']() != 1",
    }, {
      "note" = "the plains gully and the scavenge windbreak",
      "expr" = "m['wnsPlainsGully']() != 1 or m['wnsPlainsScavengeWindbreak']() != 1 or m['wnsPlainMtnImpossible']() != 1",
    }, {
      "note" = "the shelter-quality guidelines: many-small poor, few-large good, the rock-side wind split",
      "expr" = "m['wnsQualityManySmallPoor']() != 1 or m['wnsQualityFewLargeGood']() != 1 or m['wnsRockSideWindGood']() != 1",
    } },
  "audit" = {
      "label" = "R471 WSG natural shelters pin audit",
      "comment" = "The Table 35 grid (the six-terrain by four-season chance of finding natural shelter), the check discipline (the DM checks whenever characters look, further checks at three-turn intervals), the forest construction ladder (the 3-8 turn material time with the helper reduction, the 6-turn lashing, the rope use halving), the plains ladder (7-12 turns), the terrain notes (the desert surface irregularities, the hills windbreak, the mountains-as-features reading, the plains gully, the swamp debris) and the shelter-quality guidelines - every const, bool and table cell verified against the model.",
    },
}
