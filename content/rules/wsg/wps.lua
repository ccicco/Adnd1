-- wps: promoted from tools/spec_r472.json (the R472: the WSG PORTABLE SHELTERS slice with TABLE 36 - the p. 61 seam tail (a cave in the face of a mountain slope is a superior shelter in all respects, assuming the opening faces away from the wind; the Dungeon Master judgment prevailing in any circumstances not covered), the portable shelter basics (characters mindful of the need for shelter carrying the appropriate materials; a single mount or size M pack animal easily transporting all the gear for many shelter types with plenty of carrying capacity left over; in the absence of an animal a single average-strength character hauling on his back enough for himself and a small group at their rest stops), the simplest form (a single wooden pole of 6-10 feet plus a fairly large expanse of heavy, waterproofed cloth or similarly pliable material; the DM may allow a two- or three-piece pole apparatus held by lashings or pegs, easier to transport), the pitch rules (the pole anchored at 30 to 45 degrees, one end braced on the ground and the other a few feet in the air, the covering draped over the pole, the edges touching the ground or tied down with ropes and stakes, the opening facing opposite the wind), the occupancy (enough space for one human or a pair of smaller characters, and in a pinch two men with no appreciable loss of protection or comfort), the escalation (more elaborate and larger shelters necessary for especially vicious weather or a decent-sized group huddling in one tent) and Table 36 PORTABLE SHELTER CHARACTERISTICS: the four quality bands poor, adequate, good, superior by small, medium, large - encumbrance value 350/450/600, 500/600/750, 600/800/1000, 750/1000/1500; cost 10/20/30, 30/50/75, 75/120/180, 200/300/400 gold pieces; setup time 1d2+1/1d2+2/1d2+3, 1d3+1/1d3+2/1d3+3, 1d3+1/1d3+2/1d4+2, 1d4+1/1d4+2/1d4+3 turns; moisture resistance light, moderate, heavy, downpour; wind resistance 20/30/40/50 percent; life span 40/80/120/180 days), printed p. 62.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 472,
  "prefix" = "wps",
  "banner" = {
      "title" = "R472: the WSG PORTABLE SHELTERS slice with TABLE 36 - the p. 61 seam tail (a cave in the face of a mountain slope is a superior shelter in all respects, assuming the opening faces away from the wind; the Dungeon Master judgment prevailing in any circumstances not covered), the portable shelter basics (characters mindful of the need for shelter carrying the appropriate materials; a single mount or size M pack animal easily transporting all the gear for many shelter types with plenty of carrying capacity left over; in the absence of an animal a single average-strength character hauling on his back enough for himself and a small group at their rest stops), the simplest form (a single wooden pole of 6-10 feet plus a fairly large expanse of heavy, waterproofed cloth or similarly pliable material; the DM may allow a two- or three-piece pole apparatus held by lashings or pegs, easier to transport), the pitch rules (the pole anchored at 30 to 45 degrees, one end braced on the ground and the other a few feet in the air, the covering draped over the pole, the edges touching the ground or tied down with ropes and stakes, the opening facing opposite the wind), the occupancy (enough space for one human or a pair of smaller characters, and in a pinch two men with no appreciable loss of protection or comfort), the escalation (more elaborate and larger shelters necessary for especially vicious weather or a decent-sized group huddling in one tent) and Table 36 PORTABLE SHELTER CHARACTERISTICS: the four quality bands poor, adequate, good, superior by small, medium, large - encumbrance value 350/450/600, 500/600/750, 600/800/1000, 750/1000/1500; cost 10/20/30, 30/50/75, 75/120/180, 200/300/400 gold pieces; setup time 1d2+1/1d2+2/1d2+3, 1d3+1/1d3+2/1d3+3, 1d3+1/1d3+2/1d4+2, 1d4+1/1d4+2/1d4+3 turns; moisture resistance light, moderate, heavy, downpour; wind resistance 20/30/40/50 percent; life span 40/80/120/180 days), printed p. 62.",
      "provenance" = "Ground truth two-way, no contested cells, no physical-page reads: the R467 TSV-GEOMETRY WORKFLOW (the uploaded p62_tsv.tsv word boxes, the twelve-row grid rebuilt from the bounding geometry) vs the user-run Termux tesseract text of printed p. 62 (p62_full.txt). The two readers AGREE ON ALL 72 GRID CELLS (twelve rows by six columns). The pdf text layer (p62_pdfy.txt) is the third reader: it garbles the dice glyphs as ld (the known pattern) but agrees on every value and on all prose numbers - the 6-10 foot pole, the 30-45 degree pitch, the one-human occupancy with the pair-of-smaller and two-men-in-a-pinch readings. The GOOD LARGE SETUP OUTLIER 1d4+2 (breaking the 1d3+ pattern of its band) is verified in all three readers. The p. 61 seam tail (the cave sentence completing the p. 61 shelter-quality guidelines) opens the page.",
      "sentinel" = "All 72 Table 36 cells pinned (the setup time dice split into a die and a modifier column, the moisture resistance encoded as a four-step tier); the simple-shelter mechanics, the occupancy limits and the hauling rules are audit examples.",
    },
  "consts" = { {
      "name" = "wpsQualityBands",
      "value" = 4,
      "comment" = "the Table 36 quality bands: poor, adequate, good, superior",
    }, {
      "name" = "wpsSizesPerBand",
      "value" = 3,
      "comment" = "the Table 36 sizes within each band: small, medium, large",
    }, {
      "name" = "wpsRowCount",
      "value" = 12,
      "comment" = "the Table 36 row count: four quality bands x three sizes",
    }, {
      "name" = "wpsPoleMinFeet",
      "value" = 6,
      "comment" = "the simplest portable shelter uses a single wooden pole of 6-10 feet: the length floor",
    }, {
      "name" = "wpsPoleMaxFeet",
      "value" = 10,
      "comment" = "the pole length ceiling",
    }, {
      "name" = "wpsPitchMinAngle",
      "value" = 30,
      "comment" = "the pole is anchored at an angle of 30 to 45 degrees: the floor",
    }, {
      "name" = "wpsPitchMaxAngle",
      "value" = 45,
      "comment" = "the pitch angle ceiling",
    }, {
      "name" = "wpsMaxPolePieces",
      "value" = 3,
      "comment" = "the DM may allow a two- or three-piece pole apparatus held together by lashings or pegs, easier to transport",
    } },
  "bools" = { {
      "name" = "wpsCaveSlopeSuperior",
      "value" = true,
      "comment" = "a cave in the face of a mountain slope is a superior shelter in all respects, assuming the opening faces away from the wind - the p. 61 seam tail",
    }, {
      "name" = "wpsDmJudgmentPrevails",
      "value" = true,
      "comment" = "the Dungeon Master judgment will prevail in any circumstances not covered by the shelter guidelines",
    }, {
      "name" = "wpsMindfulCarryGear",
      "value" = true,
      "comment" = "characters properly mindful of the need for good shelter in the wilderness will carry the appropriate materials with them",
    }, {
      "name" = "wpsPackAnimalHauls",
      "value" = true,
      "comment" = "a single mount or size M pack animal can easily transport all the gear needed for many types of shelters with plenty of carrying capacity left over",
    }, {
      "name" = "wpsAvgCharHauls",
      "value" = true,
      "comment" = "in the absence of an animal, a single character of average strength can usually haul on his back enough shelter materials to keep himself and a small group of companions comfortable during their rest stops",
    }, {
      "name" = "wpsWaterproofClothCover",
      "value" = true,
      "comment" = "in its simplest form a portable shelter is a single pole plus a fairly large expanse of heavy, waterproofed cloth or some similarly pliable material",
    }, {
      "name" = "wpsMultiPiecePole",
      "value" = true,
      "comment" = "the DM may decide the framework pole need not be a single piece but a two- or three-piece apparatus with the parts held together by lashings or pegs when assembled",
    }, {
      "name" = "wpsPitchAwayFromWind",
      "value" = true,
      "comment" = "to pitch a simple tent the pole is braced at 30 to 45 degrees, the covering draped over it, the edges tied down with ropes and stakes, and the opening in front facing opposite the direction the wind is coming from",
    }, {
      "name" = "wpsSimpleFitsOneHuman",
      "value" = true,
      "comment" = "this kind of simple shelter provides enough space for one human or a pair of smaller characters",
    }, {
      "name" = "wpsTwoMenInPinch",
      "value" = true,
      "comment" = "in a pinch two men can use the simple shelter with no appreciable loss of protection or comfort",
    }, {
      "name" = "wpsElaborateForVicious",
      "value" = true,
      "comment" = "more elaborate and larger shelters are necessary if the weather is especially vicious or if all the characters in a decent-sized group intend to huddle inside the same tent",
    }, {
      "name" = "wpsCategoryByQualityAndCapacity",
      "value" = true,
      "comment" = "for game purposes portable shelters come in categories related to the quality of protection they provide and the number of man-sized characters they can comfortably contain",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "wpsShelterChars",
      "tag" = "36",
      "count" = "wpsRowCount",
      "cols" = { "wpsEncValue", "wpsCost", "wpsSetupDie", "wpsSetupMod", "wpsMoistTier", "wpsWindRes", "wpsLifeSpan" },
      "col_default" = 0,
      "col_comments" = { "the Table 36 encumbrance value by quality band and size", "the Table 36 cost in gold pieces", "the Table 36 setup time die: rolls of 1d2+1 through 1d4+3 turns", "the Table 36 setup time modifier added to the die", "the Table 36 moisture resistance tier: 0 light, 1 moderate, 2 heavy, 3 downpour", "the Table 36 wind resistance percent", "the Table 36 life span in days" },
      "row_comments" = { "the poor small row", "the poor medium row", "the poor large row", "the adequate small row", "the adequate medium row", "the adequate large row", "the good small row", "the good medium row", "the good large row", "the superior small row", "the superior medium row", "the superior large row" },
      "data" = { { 350, 10, 2, 1, 0, 20, 40 }, { 450, 20, 2, 2, 0, 20, 40 }, { 600, 30, 2, 3, 0, 20, 40 }, { 500, 30, 3, 1, 1, 30, 80 }, { 600, 50, 3, 2, 1, 30, 80 }, { 750, 75, 3, 3, 1, 30, 80 }, { 600, 75, 3, 1, 2, 40, 120 }, { 800, 120, 3, 2, 2, 40, 120 }, { 1000, 180, 4, 2, 2, 40, 120 }, { 750, 200, 4, 1, 3, 50, 180 }, { 1000, 300, 4, 2, 3, 50, 180 }, { 1500, 400, 4, 3, 3, 50, 180 } },
      "audit_comment" = "Table 36: portable shelter characteristics, the four-quality-band by three-size grid (encumbrance value, cost, setup time dice, moisture resistance tier, wind resistance, life span), printed p. 62",
      "sentinel" = 999,
      "sentinel_census" = { 0, 0, 0, 0, 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "note" = "the pole ladder: 6-10 feet",
      "expr" = "m['wpsPoleMinFeet']() != 6 or m['wpsPoleMaxFeet']() != 10 or m['wpsPoleMinFeet']() >= m['wpsPoleMaxFeet']()",
    }, {
      "note" = "the pitch ladder: 30 to 45 degrees",
      "expr" = "m['wpsPitchMinAngle']() != 30 or m['wpsPitchMaxAngle']() != 45 or m['wpsPitchMinAngle']() >= m['wpsPitchMaxAngle']()",
    }, {
      "note" = "the pole pieces: a two- or three-piece apparatus at most",
      "expr" = "m['wpsMaxPolePieces']() != 3",
    }, {
      "note" = "the grid geometry: four bands of three sizes, twelve rows",
      "expr" = "m['wpsQualityBands']() != 4 or m['wpsSizesPerBand']() != 3 or m['wpsRowCount']() != 12",
    }, {
      "note" = "the p. 61 seam tail and the DM judgment",
      "expr" = "m['wpsCaveSlopeSuperior']() != 1 or m['wpsDmJudgmentPrevails']() != 1",
    }, {
      "note" = "the hauling rules: the pack animal and the average-strength character",
      "expr" = "m['wpsMindfulCarryGear']() != 1 or m['wpsPackAnimalHauls']() != 1 or m['wpsAvgCharHauls']() != 1",
    }, {
      "note" = "the simple shelter: waterproof cloth, the multi-piece pole option and the pitch discipline",
      "expr" = "m['wpsWaterproofClothCover']() != 1 or m['wpsMultiPiecePole']() != 1 or m['wpsPitchAwayFromWind']() != 1",
    }, {
      "note" = "the occupancy: one human or a pair of smaller characters, two men in a pinch",
      "expr" = "m['wpsSimpleFitsOneHuman']() != 1 or m['wpsTwoMenInPinch']() != 1",
    }, {
      "note" = "the category basis and the vicious-weather escalation",
      "expr" = "m['wpsCategoryByQualityAndCapacity']() != 1 or m['wpsElaborateForVicious']() != 1",
    } },
  "audit" = {
      "label" = "R472 WSG portable shelters pin audit",
      "comment" = "The Table 36 grid (the four-quality-band by three-size portable shelter characteristics: encumbrance value, cost, setup time dice, moisture tier, wind resistance, life span), the simple shelter mechanics (the 6-10 foot pole, the waterproof cloth, the 30-45 degree pitch, the ropes and stakes, the opening away from the wind), the occupancy limits (one human, two smaller characters, two men in a pinch), the hauling rules and the p. 61 cave-slope seam tail - every const, bool and table cell verified against the model.",
    },
}
