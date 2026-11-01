-- wfg: promoted from tools/spec_r463.json (the R463: the WSG FOOD GATHERING AND FORAGING slice - the foraging check with the proficiency advantage, Table 30 (the 33-row terrain-by-season foraging success grid over the five climate regions) and the inedible plants dispatch, printed pp. 53-54.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 463,
  "prefix" = "wfg",
  "banner" = {
      "title" = "R463: the WSG FOOD GATHERING AND FORAGING slice - the foraging check with the proficiency advantage, Table 30 (the 33-row terrain-by-season foraging success grid over the five climate regions) and the inedible plants dispatch, printed pp. 53-54.",
      "provenance" = "Ground truth three-way: the archive djvu word layer vs the pdfy PDF text layer vs the pixel reads of the Table 30 scan (leaf 0053 of the pdfy item, full native 2432x3194 decode). The two text layers disagree or drop the Tem-F winter, St-P/Se/Sw winter, Tro-M winter and Tro-Se spring cells and both garble the Arctic P and Se rows - the pixels settled every one: a glyph-level NCC classifier over same-page font templates (leave-one-out 62/62) plus vision reads of the contrast-stretched cell crops, every disputed digit at 0.83-0.94 correlation with the runner-up 0.2-0.3 behind.",
      "sentinel" = "All 132 grid cells pinned; the foraging mechanics (the two-turn check, the proficient 2-in-2 or 1-in-1, the -20 inedible shift, the four-turn search limit, the one-mile move-on, the 1d8 inedible bands) are audit examples.",
    },
  "consts" = { {
      "name" = "wfgCheckTurnsNormal",
      "value" = 2,
      "comment" = "a normal character forages two turns per check: the chance to find one full day's ration",
    }, {
      "name" = "wfgRationPounds",
      "value" = 2,
      "comment" = "one full day's ration of plant life is two pounds of fruit, vegetables and/or greenery",
    }, {
      "name" = "wfgProfRationsPerCheck",
      "value" = 2,
      "comment" = "with the foraging proficiency: two full rations located in the same two turns of foraging",
    }, {
      "name" = "wfgProfTurnsPerRation",
      "value" = 1,
      "comment" = "with the proficiency: one full ration located in one turn of foraging",
    }, {
      "name" = "wfgProfInedibleReduction",
      "value" = 20,
      "comment" = "with the proficiency: the chance of the take being inedible is 20% lower than a normal character's",
    }, {
      "name" = "wfgSearchTurnsMax",
      "value" = 4,
      "comment" = "fruitless to spend more than four turns attempting to find food - no further searching produces better results",
    }, {
      "name" = "wfgChecksMaxNormal",
      "value" = 2,
      "comment" = "the four-turn limit is two foraging checks for a normal character",
    }, {
      "name" = "wfgChecksMaxProf",
      "value" = 4,
      "comment" = "the four-turn limit is four foraging checks for one with the proficiency",
    }, {
      "name" = "wfgMilesBeforeReforage",
      "value" = 1,
      "comment" = "after a fruitless search the group must travel at least one mile before foraging again",
    }, {
      "name" = "wfgArcRowCount",
      "value" = 5,
      "comment" = "the Table 30 Arctic grid rows: desert, hills, mountains, plains and scrublands - no forest or swamp row",
    }, {
      "name" = "wfgSubRowCount",
      "value" = 7,
      "comment" = "the Table 30 Subarctic grid rows (the standard seven terrains)",
    }, {
      "name" = "wfgTemRowCount",
      "value" = 7,
      "comment" = "the Table 30 Temperate grid rows (the standard seven terrains)",
    }, {
      "name" = "wfgStiRowCount",
      "value" = 7,
      "comment" = "the Table 30 Subtropical grid rows (the standard seven terrains)",
    }, {
      "name" = "wfgTroRowCount",
      "value" = 7,
      "comment" = "the Table 30 Tropical grid rows (the standard seven terrains)",
    }, {
      "name" = "wfgInedRollMax",
      "value" = 8,
      "comment" = "the inedible-plants dispatch roll is 1d8",
    }, {
      "name" = "wfgPoisonCrampOnsetDie",
      "value" = 10,
      "comment" = "poisonous plants: cramps begin 1d10 rounds after eating",
    }, {
      "name" = "wfgPoisonCrampTurnsDice",
      "value" = 2,
      "comment" = "poisonous plants: the cramps last 2d10 turns",
    }, {
      "name" = "wfgPoisonCrampTurnsDie",
      "value" = 10,
      "comment" = "poisonous plants: the cramp duration die is d10",
    }, {
      "name" = "wfgPoisonHpPerTurnDie",
      "value" = 4,
      "comment" = "poisonous plants: 1d4 hit points lost per turn while the cramps persist",
    }, {
      "name" = "wfgPoisonRegainPerHourDie",
      "value" = 4,
      "comment" = "poisonous plants: hit points regained at 1d4 per hour with rest",
    }, {
      "name" = "wfgPoisonRestWaterPintsPerHour",
      "value" = 1,
      "comment" = "the poison recovery requires at least one pint of water per hour while resting",
    }, {
      "name" = "wfgSlowPoisonSaveStackNum",
      "value" = 1,
      "comment" = "slow poison on a character who made his save: one-fourth duration and damage",
    }, {
      "name" = "wfgSlowPoisonSaveStackDen",
      "value" = 4,
      "comment" = "slow poison on a character who made his save: the one-fourth denominator",
    }, {
      "name" = "wfgTaintCrampOnsetDie",
      "value" = 10,
      "comment" = "tainted plants: cramps begin within 1d10 rounds",
    }, {
      "name" = "wfgTaintCrampTurnsDie",
      "value" = 10,
      "comment" = "tainted plants: the cramps last 1d10 turns",
    }, {
      "name" = "wfgTaintHpPerTurnDie",
      "value" = 2,
      "comment" = "tainted plants: 1d2 hit points lost per turn while the cramps persist",
    }, {
      "name" = "wfgTaintHalfNum",
      "value" = 1,
      "comment" = "tainted plants affect the consumer as half-strength poison",
    }, {
      "name" = "wfgTaintHalfDen",
      "value" = 2,
      "comment" = "the tainted half-strength denominator",
    } },
  "bools" = { {
      "name" = "wfgProfFindChanceNormal",
      "value" = true,
      "comment" = "the proficient character's chance of locating potentially edible plants is no greater than any other character's",
    }, {
      "name" = "wfgPoisonHalfRationTriggers",
      "value" = true,
      "comment" = "poisonous plants hit anyone who eats a half-ration or more",
    }, {
      "name" = "wfgPoisonSaveHalves",
      "value" = true,
      "comment" = "a saving throw versus poison halves both the cramp duration and the damage",
    }, {
      "name" = "wfgSlowPoisonActsAsSave",
      "value" = true,
      "comment" = "a slow poison spell acts the same as a successful saving throw",
    }, {
      "name" = "wfgNeutralizeHaltsCramps",
      "value" = true,
      "comment" = "a neutralize poison spell halts the cramps and negates any damage that would be suffered subsequently",
    }, {
      "name" = "wfgNeutralizeNoPriorDamage",
      "value" = true,
      "comment" = "neutralize poison does not negate damage taken before the spell was applied",
    }, {
      "name" = "wfgTaintSaveHalves",
      "value" = true,
      "comment" = "tainted plants: a saving throw versus poison reduces duration and damage by half",
    }, {
      "name" = "wfgTaintCureDiseaseHalts",
      "value" = true,
      "comment" = "tainted plants: a neutralize poison or cure disease spell halts duration and damage as soon as it is cast",
    }, {
      "name" = "wfgNoValueWaterOnly",
      "value" = true,
      "comment" = "the 5-8 no-value plants provide no food value aside from the water they might contain",
    }, {
      "name" = "wfgNoValueFullNoNourish",
      "value" = true,
      "comment" = "no-value plants fill the stomach but affect the system as though no food was eaten",
    }, {
      "name" = "wfgOrchardGuaranteed",
      "value" = true,
      "comment" = "camp in an apple grove or a cornfield edge: a 100% chance of coming back with food, whatever the table says",
    }, {
      "name" = "wfgRipePickedInedibleNearZero",
      "value" = true,
      "comment" = "gathering all the ripe fruit from the trees instead of picking some up off the ground: little or no chance the food is inedible",
    }, {
      "name" = "wfgTableNotUnerring",
      "value" = true,
      "comment" = "the table must not unswervingly dictate what happens - common sense and reasonable judgment prevail",
    }, {
      "name" = "wfgGroupMustMoveOn",
      "value" = true,
      "comment" = "if every character searches the limit and no food is found, the group must move on before foraging again",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "wfgArcForage",
      "tag" = "30A",
      "count" = "wfgArcRowCount",
      "cols" = { "wfgArcWinChn", "wfgArcWinInd", "wfgArcSprChn", "wfgArcSprInd", "wfgArcSumChn", "wfgArcSumInd", "wfgArcAutChn", "wfgArcAutInd" },
      "col_default" = 0,
      "col_comments" = { "the Table 30 Win foraging chance (percent, two turns)", "the Table 30 Win inedible chance (percent of the take)", "the Table 30 Spr foraging chance (percent, two turns)", "the Table 30 Spr inedible chance (percent of the take)", "the Table 30 Sum foraging chance (percent, two turns)", "the Table 30 Sum inedible chance (percent of the take)", "the Table 30 Aut foraging chance (percent, two turns)", "the Table 30 Aut inedible chance (percent of the take)" },
      "row_comments" = { "the desert row", "the hills row", "the mountains row", "the plains row", "the scrublands row" },
      "data" = { { 0, 0, 5, 75, 10, 75, 0, 0 }, { 5, 75, 10, 60, 10, 60, 5, 50 }, { 0, 0, 0, 0, 5, 50, 0, 0 }, { 5, 50, 5, 50, 10, 50, 5, 50 }, { 10, 75, 10, 50, 15, 50, 10, 75 } },
      "audit_comment" = "the Table 30 Arctic terrain grid (chance/inedible per season)",
    }, {
      "name" = "wfgSubForage",
      "tag" = "30B",
      "count" = "wfgSubRowCount",
      "cols" = { "wfgSubWinChn", "wfgSubWinInd", "wfgSubSprChn", "wfgSubSprInd", "wfgSubSumChn", "wfgSubSumInd", "wfgSubAutChn", "wfgSubAutInd" },
      "col_default" = 0,
      "col_comments" = { "the Table 30 Win foraging chance (percent, two turns)", "the Table 30 Win inedible chance (percent of the take)", "the Table 30 Spr foraging chance (percent, two turns)", "the Table 30 Spr inedible chance (percent of the take)", "the Table 30 Sum foraging chance (percent, two turns)", "the Table 30 Sum inedible chance (percent of the take)", "the Table 30 Aut foraging chance (percent, two turns)", "the Table 30 Aut inedible chance (percent of the take)" },
      "row_comments" = { "the desert row", "the forest row", "the hills row", "the mountains row", "the plains row", "the scrublands row", "the swamp row" },
      "data" = { { 0, 0, 5, 50, 15, 50, 5, 75 }, { 70, 40, 85, 40, 100, 50, 75, 40 }, { 20, 50, 30, 50, 40, 40, 25, 50 }, { 10, 50, 15, 50, 20, 40, 15, 50 }, { 20, 40, 30, 40, 50, 40, 30, 50 }, { 25, 60, 35, 50, 50, 40, 35, 50 }, { 15, 60, 20, 60, 30, 60, 20, 50 } },
      "audit_comment" = "the Table 30 Subarctic terrain grid (chance/inedible per season)",
    }, {
      "name" = "wfgTemForage",
      "tag" = "30C",
      "count" = "wfgTemRowCount",
      "cols" = { "wfgTemWinChn", "wfgTemWinInd", "wfgTemSprChn", "wfgTemSprInd", "wfgTemSumChn", "wfgTemSumInd", "wfgTemAutChn", "wfgTemAutInd" },
      "col_default" = 0,
      "col_comments" = { "the Table 30 Win foraging chance (percent, two turns)", "the Table 30 Win inedible chance (percent of the take)", "the Table 30 Spr foraging chance (percent, two turns)", "the Table 30 Spr inedible chance (percent of the take)", "the Table 30 Sum foraging chance (percent, two turns)", "the Table 30 Sum inedible chance (percent of the take)", "the Table 30 Aut foraging chance (percent, two turns)", "the Table 30 Aut inedible chance (percent of the take)" },
      "row_comments" = { "the desert row", "the forest row", "the hills row", "the mountains row", "the plains row", "the scrublands row", "the swamp row" },
      "data" = { { 10, 70, 5, 50, 5, 70, 5, 50 }, { 80, 40, 90, 40, 100, 40, 90, 40 }, { 65, 50, 75, 40, 90, 35, 80, 50 }, { 20, 40, 30, 40, 40, 40, 30, 50 }, { 50, 40, 60, 40, 75, 30, 60, 50 }, { 50, 50, 65, 40, 80, 40, 65, 50 }, { 30, 60, 35, 50, 40, 50, 35, 60 } },
      "audit_comment" = "the Table 30 Temperate terrain grid (chance/inedible per season)",
    }, {
      "name" = "wfgStiForage",
      "tag" = "30D",
      "count" = "wfgStiRowCount",
      "cols" = { "wfgStiWinChn", "wfgStiWinInd", "wfgStiSprChn", "wfgStiSprInd", "wfgStiSumChn", "wfgStiSumInd", "wfgStiAutChn", "wfgStiAutInd" },
      "col_default" = 0,
      "col_comments" = { "the Table 30 Win foraging chance (percent, two turns)", "the Table 30 Win inedible chance (percent of the take)", "the Table 30 Spr foraging chance (percent, two turns)", "the Table 30 Spr inedible chance (percent of the take)", "the Table 30 Sum foraging chance (percent, two turns)", "the Table 30 Sum inedible chance (percent of the take)", "the Table 30 Aut foraging chance (percent, two turns)", "the Table 30 Aut inedible chance (percent of the take)" },
      "row_comments" = { "the desert row", "the forest row", "the hills row", "the mountains row", "the plains row", "the scrublands row", "the swamp row" },
      "data" = { { 5, 75, 5, 80, 0, 0, 5, 75 }, { 90, 30, 100, 30, 100, 30, 100, 30 }, { 80, 30, 90, 30, 100, 25, 95, 25 }, { 40, 40, 55, 30, 75, 30, 60, 40 }, { 80, 30, 90, 30, 100, 30, 100, 35 }, { 80, 40, 90, 40, 100, 40, 95, 40 }, { 40, 60, 50, 50, 50, 50, 50, 60 } },
      "audit_comment" = "the Table 30 Subtropical terrain grid (chance/inedible per season)",
    }, {
      "name" = "wfgTroForage",
      "tag" = "30E",
      "count" = "wfgTroRowCount",
      "cols" = { "wfgTroWinChn", "wfgTroWinInd", "wfgTroSprChn", "wfgTroSprInd", "wfgTroSumChn", "wfgTroSumInd", "wfgTroAutChn", "wfgTroAutInd" },
      "col_default" = 0,
      "col_comments" = { "the Table 30 Win foraging chance (percent, two turns)", "the Table 30 Win inedible chance (percent of the take)", "the Table 30 Spr foraging chance (percent, two turns)", "the Table 30 Spr inedible chance (percent of the take)", "the Table 30 Sum foraging chance (percent, two turns)", "the Table 30 Sum inedible chance (percent of the take)", "the Table 30 Aut foraging chance (percent, two turns)", "the Table 30 Aut inedible chance (percent of the take)" },
      "row_comments" = { "the desert row", "the forest row", "the hills row", "the mountains row", "the plains row", "the scrublands row", "the swamp row" },
      "data" = { { 5, 75, 5, 80, 0, 0, 5, 75 }, { 100, 30, 100, 30, 100, 40, 100, 30 }, { 90, 30, 100, 40, 100, 40, 95, 35 }, { 85, 30, 90, 30, 90, 40, 90, 35 }, { 100, 30, 100, 45, 100, 50, 100, 40 }, { 90, 40, 95, 50, 100, 50, 95, 50 }, { 50, 60, 60, 60, 70, 50, 60, 60 } },
      "audit_comment" = "the Table 30 Tropical terrain grid (chance/inedible per season)",
    } },
  "chains" = { {
      "name" = "wfgInedBandFor",
      "arg" = "r",
      "limits" = { 1, 4 },
      "tail" = 2,
      "comment" = "the inedible-plants band on 1d8: 1 poisonous band 0, 2-4 tainted band 1, 5-8 no food value band 2",
    } },
  "examples" = { {
      "note" = "the subarctic forest winter forage: 70% find chance, 40% inedible",
      "expr" = "m['wfgSubWinChn'](1) != 70 or m['wfgSubWinInd'](1) != 40",
    }, {
      "note" = "the proficient take: two rations per two-turn check or one per turn",
      "expr" = "m['wfgProfRationsPerCheck']() != 2 or m['wfgProfTurnsPerRation']() != 1",
    }, {
      "note" = "the proficient inedible shift on the temperate forest spring cell: 40 - 20 = 20",
      "expr" = "m['wfgTemSprInd'](1) - m['wfgProfInedibleReduction']() != 20",
    }, {
      "note" = "the search limit: four turns is two normal checks, four proficient checks",
      "expr" = "m['wfgSearchTurnsMax']() != m['wfgChecksMaxNormal']() * m['wfgCheckTurnsNormal']() or m['wfgSearchTurnsMax']() != m['wfgChecksMaxProf']() * m['wfgProfTurnsPerRation']()",
    }, {
      "note" = "the ration weight: one day's ration is two pounds",
      "expr" = "m['wfgRationPounds']() != 2",
    }, {
      "note" = "the arctic desert winter: nothing to find",
      "expr" = "m['wfgArcWinChn'](0) != 0 or m['wfgArcWinInd'](0) != 0",
    }, {
      "note" = "the move-on rule: at least one mile before foraging again",
      "expr" = "m['wfgMilesBeforeReforage']() != 1",
    } },
  "audit" = {
      "label" = "R463 WSG foraging pin audit",
      "comment" = "The Table 30 grid cell by cell (five climate regions, the chance and inedible percent per terrain per season), the two-turn foraging check with the proficiency advantage and the four-turn search limit, the 1d8 inedible dispatch with the poison and tainted cramp and dice rules - every cell, const, bool and chain limit verified against the model.",
    },
}
