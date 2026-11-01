-- dnv: promoted from tools/spec_r510.json (the The DSG ODOR DETECTION, R510: the printed pp. 37-38 (pdf 38-39) - the opener (the sense of smell giving advance warning of nearby hazards, useful only with no overpowering scent nearby), the Wisdom Check procedure (at first encounter, secret and non-repeating, rechecked only on a stronger scent or a harder wind, full Wisdom only for easily-noticed odors), the dog rules (Wisdom 16 for this check only, the doubled distance before the negative modifiers, described reactions and trained responses), the Table 15 row definitions (the fire sizes at 1 and 6-8 feet, the oil and conflagration categories, the odorous gases, the three creature odor strengths with the 50% lair-scent roll, cooking food), the Table 15 detection grid across the four distance bands with the printed dash for no detection, the Table 16 wind effects on odors (strong, medium and light winds against upwind, crosswind and downwind sources) and the wind definitions (upwind from the source, downwind away, crosswind perpendicular; strong winds extinguishing torches, medium flickering them, light almost unnoticeable));
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 510,
  "prefix" = "dnv",
  "banner" = {
      "title" = "The DSG ODOR DETECTION, R510: the printed pp. 37-38 (pdf 38-39) - the opener (the sense of smell giving advance warning of nearby hazards, useful only with no overpowering scent nearby), the Wisdom Check procedure (at first encounter, secret and non-repeating, rechecked only on a stronger scent or a harder wind, full Wisdom only for easily-noticed odors), the dog rules (Wisdom 16 for this check only, the doubled distance before the negative modifiers, described reactions and trained responses), the Table 15 row definitions (the fire sizes at 1 and 6-8 feet, the oil and conflagration categories, the odorous gases, the three creature odor strengths with the 50% lair-scent roll, cooking food), the Table 15 detection grid across the four distance bands with the printed dash for no detection, the Table 16 wind effects on odors (strong, medium and light winds against upwind, crosswind and downwind sources) and the wind definitions (upwind from the source, downwind away, crosswind perpendicular; strong winds extinguishing torches, medium flickering them, light almost unnoticeable)",
      "provenance" = "the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf = printed + 1; the text read from the IA djvu OCR with the pdf Acrobat-Capture layer as the second read - every numeric cell dual-confirmed, with a THREE-WAY settlement for the disputed small-fires row: the chapter djvu read \"9, -4, -8, (c)\" is corrected by the book's own compiled-tables appendix reprint (djvu.txt line 15520: \"small 0 -4 -B -\") and by the design ladder (every other cell even, the rows stepping in 2s and 4s) to 0, -4, -8, dash; the appendix garbles *2 = +2, T. = -4, 22 = -2, =6 = -6, =2 = -2, -B = -8; the Table 16 garbles 110 = 1/10, I4 = 1/4, the Acrobat 112 = 1/2. The CAVE-INS heading and the causes prose on the same printed page start the NEXT round per the content-density rule (the R507-to-R508 tail precedent).",
      "sentinel" = "Table 15 pins as a 9x5 grid with the -99 sentinel for the printed dash (sentinel census 0/0/0/1/3: the small row and mild-odor row undetectable at 1000-5000 feet, the no-odor row undetectable past 360 feet). Table 16 pins in the percent-of-distance encoding: Normal 100, 1/2 = 50, No detection 0, Double 200, 1/10 = 10, 1/4 = 25. The R509 dnaOdorlessGasNoWisCheck pin is the p. 37 prose seam of this section - nothing auto-credited.",
    },
  "consts" = { {
      "name" = "dnvDogWisScore",
      "value" = 16,
      "comment" = "dogs are all assumed to have a Wisdom of 16, for purposes of this check only.",
    }, {
      "name" = "dnvOdorDogDistanceMult",
      "value" = 2,
      "comment" = "if a dog is making the check, double the distance listed on Table 15 before implementing the negative modifiers.",
    }, {
      "name" = "dnvFireSmallMaxDiameterFt",
      "value" = 1,
      "comment" = "small fires are used for cooking or keeping a small group of individuals warm; they are generally one foot or less in diameter.",
    }, {
      "name" = "dnvFireLargeMinDiameterFt",
      "value" = 6,
      "comment" = "large fires - bonfires, large campfires, funeral pyres and other relatively sizeable but controlled blazes - can be 6-8 feet in diameter: the low end.",
    }, {
      "name" = "dnvFireLargeMaxDiameterFt",
      "value" = 8,
      "comment" = "a large fire can be 6-8 feet in diameter, with the flames rising even higher: the high end.",
    }, {
      "name" = "dnvStrongOdorLairPct",
      "value" = 50,
      "comment" = "the area near the lair of a strong-odor creature always carries the distinctive scent, but it is only 50% likely to be encountered if the creature is prowling outside of its lair.",
    }, {
      "name" = "dnvOdorBand1MaxFt",
      "value" = 120,
      "comment" = "the first distance band runs 1-120 feet from the source.",
    }, {
      "name" = "dnvOdorBand2MinFt",
      "value" = 121,
      "comment" = "the second distance band opens at 121 feet.",
    }, {
      "name" = "dnvOdorBand2MaxFt",
      "value" = 360,
      "comment" = "the second distance band closes at 360 feet.",
    }, {
      "name" = "dnvOdorBand3MinFt",
      "value" = 361,
      "comment" = "the third distance band opens at 361 feet.",
    }, {
      "name" = "dnvOdorBand3MaxFt",
      "value" = 1000,
      "comment" = "the third distance band closes at 1000 feet.",
    }, {
      "name" = "dnvOdorBand4MinFt",
      "value" = 1000,
      "comment" = "the fourth distance band opens at 1000 feet.",
    }, {
      "name" = "dnvOdorBand4MaxFt",
      "value" = 5000,
      "comment" = "the fourth distance band closes at 5000 feet.",
    }, {
      "name" = "dnvT15RowCount",
      "value" = 9,
      "comment" = "the Table 15 carries nine odor sources: four fire sizes, one gas, three creature strengths and cooking food.",
    }, {
      "name" = "dnvT16RowCount",
      "value" = 3,
      "comment" = "the Table 16 carries three wind forces: strong, medium and light.",
    } },
  "bools" = { {
      "name" = "dnvOdorWisCheckOnFirstEncounter",
      "value" = true,
      "comment" = "the basic procedure for a character to detect an odor is a Wisdom Check made when the scent is first encountered.",
    }, {
      "name" = "dnvOdorRecheckOnStrongerScent",
      "value" = true,
      "comment" = "another check may be made if the scent grows very strong.",
    }, {
      "name" = "dnvOdorRecheckOnWindShift",
      "value" = true,
      "comment" = "another check may also be made if a change in the wind carries the scent to the character with increased force.",
    }, {
      "name" = "dnvOdorOnlyWithoutOverpoweringScent",
      "value" = true,
      "comment" = "this sense is only useful to a character when no other overpowering scent is in close proximity to him or permeating the area.",
    }, {
      "name" = "dnvOdorCheckMadeByDm",
      "value" = true,
      "comment" = "the Wisdom Check should be made by the DM so that the players are not alerted that they should be on the lookout for something.",
    }, {
      "name" = "dnvOdorNotRepeatedIfMissed",
      "value" = true,
      "comment" = "if an odor is not noticed when it is first encountered, it will probably not be noticed thereafter unless something occurs to draw the characters' attention to it.",
    }, {
      "name" = "dnvOdorFullWisOnlyIfEasilyNoticed",
      "value" = true,
      "comment" = "the Wisdom Check is only made using the character's full Wisdom score if the odor is strong enough to be easily noticed - the strength of an odor is a DM judgment call.",
    }, {
      "name" = "dnvOdorCrossRefIsWisMod",
      "value" = true,
      "comment" = "the number found by cross-referencing the source of the odor with the character's distance from the source is a modifier to the Wisdom Check.",
    }, {
      "name" = "dnvOdorDashMeansNoDetection",
      "value" = true,
      "comment" = "a dash in the Table 15 grid indicates that the odor cannot be detected that far away.",
    }, {
      "name" = "dnvDogCheckWhenAlerted",
      "value" = true,
      "comment" = "if the party has any dogs accompanying them, the DM may also check for the dogs if they would be alerted by the scent - the scent of a monster would almost certainly alert them, while the odor of a campfire probably would not.",
    }, {
      "name" = "dnvDogReactionDescribed",
      "value" = true,
      "comment" = "if a dog smells something, the DM should describe the dog's reaction in appropriate terms - a growl of warning, perhaps, or a cringe of fear.",
    }, {
      "name" = "dnvDogTrainedReactionUsed",
      "value" = true,
      "comment" = "if a dog has been trained to react in a certain way, then that reaction should be used; sophisticated responses require considerable training.",
    }, {
      "name" = "dnvOilFireCategory",
      "value" = true,
      "comment" = "oil fires are fires where oil, creosote, or coal is burning; some pungent chemicals, when burned, create fires in this category.",
    }, {
      "name" = "dnvConflagrationCategory",
      "value" = true,
      "comment" = "conflagrations are huge fires, often burning out of control; a large boat, a bridge, or a building creates a conflagration when it burns.",
    }, {
      "name" = "dnvOdorousGasCategory",
      "value" = true,
      "comment" = "odorous gases are those with distinctive smells, such as sulphur or methane (swamp gas).",
    }, {
      "name" = "dnvStrongOdorCreatureCategory",
      "value" = true,
      "comment" = "strong-odor creatures use an odor as a means of marking terrain (such as males among the great cats) or defending themselves (such as skunks).",
    }, {
      "name" = "dnvMildOdorCreatureCategory",
      "value" = true,
      "comment" = "mild-odor creatures are those whose living quarters or presence is generally accompanied by a distinctive odor - pigs, most herd animals (especially domestic ones), and bands of orcs or other humanoid types with somewhat casual personal hygiene habits.",
    }, {
      "name" = "dnvNoOdorCreatureCategory",
      "value" = true,
      "comment" = "no-odor creatures are those that take care to remove sources of odor from their lairs - humans fall into this category, as do birds and reptiles.",
    }, {
      "name" = "dnvCookingFoodCategory",
      "value" = true,
      "comment" = "cooking food is just that.",
    }, {
      "name" = "dnvWindForceModifierWhenCurrents",
      "value" = true,
      "comment" = "if any currents of air are prevalent in the underground area, the wind direction can serve as an additional modifier to odor detection - Table 16 lists the modifications to the distances at which odors are detectable.",
    }, {
      "name" = "dnvWindHalfMeansHalfDistance",
      "value" = true,
      "comment" = "a distance factor listed as 1/2 on Table 16 means the distances for each of the Table 15 categories are reduced to 1/2 of the original.",
    }, {
      "name" = "dnvUpwindDefinition",
      "value" = true,
      "comment" = "upwind sources mean that the wind is blowing from the direction of the odor's source toward the character.",
    }, {
      "name" = "dnvDownwindDefinition",
      "value" = true,
      "comment" = "downwind means that the wind is blowing the odor away from the character.",
    }, {
      "name" = "dnvCrosswindDefinition",
      "value" = true,
      "comment" = "crosswind means that the wind is blowing perpendicular to the direction between the character and the source of the odor.",
    }, {
      "name" = "dnvStrongWindExtinguishesTorches",
      "value" = true,
      "comment" = "strong winds are those capable of extinguishing torches and other small fires, and of raising clouds of dust.",
    }, {
      "name" = "dnvMediumWindFlickersTorches",
      "value" = true,
      "comment" = "medium winds cause torches to flicker, and extinguish small flames such as candles.",
    }, {
      "name" = "dnvLightWindUnnoticeable",
      "value" = true,
      "comment" = "light winds are almost unnoticeable to characters.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "Table 15: ODOR DETECTION",
      "tag" = "15",
      "count" = "dnvT15RowCount",
      "sentinel" = -99,
      "col_default" = -99,
      "sentinel_census" = { 0, 0, 0, 1, 3 },
      "cols" = { "dnvT15Src", "dnvT15Mod1", "dnvT15Mod2", "dnvT15Mod3", "dnvT15Mod4" },
      "col_comments" = { "the row key: 0 small fire, 1 large fire, 2 oil fire, 3 conflagration, 4 odorous gas, 5 strong-odor creature, 6 mild-odor creature, 7 no-odor creature, 8 cooking food.", "the Wisdom Check modifier at 1-120 feet.", "the Wisdom Check modifier at 121-360 feet.", "the Wisdom Check modifier at 361-1000 feet.", "the Wisdom Check modifier at 1000-5000 feet; -99 = the printed dash, the odor cannot be detected that far away." },
      "audit_comment" = "the Table 15 odor detection grid",
      "data" = { { 0, 0, -4, -8, -99 }, { 1, 2, 0, -4, -8 }, { 2, 4, 2, 0, -4 }, { 3, 8, 4, 2, 0 }, { 4, 4, 2, 0, -4 }, { 5, 0, -2, -6, -10 }, { 6, -2, -6, -10, -99 }, { 7, -6, -10, -99, -99 }, { 8, 2, 0, -2, -6 } },
    }, {
      "name" = "Table 16: WIND EFFECTS ON ODORS",
      "tag" = "16",
      "count" = "dnvT16RowCount",
      "sentinel" = -99,
      "col_default" = -99,
      "cols" = { "dnvT16Force", "dnvT16Upwind", "dnvT16Crosswind", "dnvT16Downwind" },
      "col_comments" = { "the row key: 0 strong wind, 1 medium wind, 2 light wind.", "the percent of the Table 15 detection distance when the wind blows from the source toward the character (upwind): 100 = Normal, 200 = Double.", "the percent of the Table 15 detection distance when the wind blows perpendicular to the source-bearing line (crosswind): 100 = Normal, 50 = 1/2.", "the percent of the Table 15 detection distance when the wind blows the odor away from the character (downwind): 0 = No detection, 10 = 1/10, 25 = 1/4." },
      "audit_comment" = "the Table 16 wind effects grid",
      "data" = { { 0, 100, 50, 0 }, { 1, 200, 50, 10 }, { 2, 200, 100, 25 } },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dnvOdorWisCheckOnFirstEncounter']() != 1 or m['dnvOdorRecheckOnStrongerScent']() != 1 or m['dnvOdorRecheckOnWindShift']() != 1 or m['dnvOdorCheckMadeByDm']() != 1 or m['dnvOdorNotRepeatedIfMissed']() != 1",
      "note" = "the procedure: a Wisdom Check at first encounter, secret and unannounced, rechecked only when the scent grows very strong or the wind carries it harder.",
    }, {
      "expr" = "m['dnvDogWisScore']() != 16 or m['dnvOdorDogDistanceMult']() != 2 or m['dnvDogCheckWhenAlerted']() != 1",
      "note" = "the dog rules: Wisdom 16 for this check only, and the distance doubled before the negative modifiers apply, with the check made only when the scent would alert them.",
    }, {
      "expr" = "m['dnvOdorBand1MaxFt']() != 120 or m['dnvOdorBand2MinFt']() != 121 or m['dnvOdorBand2MaxFt']() != 360 or m['dnvOdorBand3MinFt']() != 361 or m['dnvOdorBand3MaxFt']() != 1000 or m['dnvOdorBand4MinFt']() != 1000 or m['dnvOdorBand4MaxFt']() != 5000",
      "note" = "the distance bands: 1-120, 121-360, 361-1000 and 1000-5000 feet from the source.",
    }, {
      "expr" = "m['dnvFireSmallMaxDiameterFt']() != 1 or m['dnvFireLargeMinDiameterFt']() != 6 or m['dnvFireLargeMaxDiameterFt']() != 8 or m['dnvStrongOdorLairPct']() != 50",
      "note" = "the row definitions: small fires one foot or less, large fires 6-8 feet, and the strong-odor lair scent only 50% likely to be encountered outside the lair.",
    }, {
      "expr" = "m['dnvT15Mod1'](0) != 0 or m['dnvT15Mod2'](0) != -4 or m['dnvT15Mod3'](0) != -8 or m['dnvT15Mod4'](0) != -99",
      "note" = "the small-fires row (the disputed cells, settled three-way by the chapter read, the compiled-tables appendix reprint and the design ladder): 0, -4, -8, and no detection at 1000-5000 feet.",
    }, {
      "expr" = "m['dnvT15Mod1'](3) != 8 or m['dnvT15Mod2'](3) != 4 or m['dnvT15Mod3'](3) != 2 or m['dnvT15Mod4'](3) != 0 or m['dnvT15Mod1'](8) != 2 or m['dnvT15Mod2'](8) != 0 or m['dnvT15Mod3'](8) != -2 or m['dnvT15Mod4'](8) != -6",
      "note" = "the conflagration row (+8/+4/+2/0, the best detection in the grid) and the cooking-food row (+2/0/-2/-6).",
    }, {
      "expr" = "m['dnvT15Mod4'](6) != -99 or m['dnvT15Mod3'](7) != -99 or m['dnvT15Mod4'](7) != -99",
      "note" = "the dash cells: mild-odor creatures undetectable at 1000-5000 feet, no-odor creatures undetectable past 360 feet.",
    }, {
      "expr" = "m['dnvT16Upwind'](0) != 100 or m['dnvT16Crosswind'](0) != 50 or m['dnvT16Downwind'](0) != 0",
      "note" = "the Table 16 strong-wind row: upwind Normal, crosswind 1/2, downwind no detection at all.",
    }, {
      "expr" = "m['dnvT16Upwind'](1) != 200 or m['dnvT16Crosswind'](1) != 50 or m['dnvT16Downwind'](1) != 10",
      "note" = "the Table 16 medium-wind row: upwind Double, crosswind 1/2, downwind 1/10.",
    }, {
      "expr" = "m['dnvT16Upwind'](2) != 200 or m['dnvT16Crosswind'](2) != 100 or m['dnvT16Downwind'](2) != 25",
      "note" = "the Table 16 light-wind row: upwind Double, crosswind Normal, downwind 1/4.",
    }, {
      "expr" = "m['dnvStrongWindExtinguishesTorches']() != 1 or m['dnvMediumWindFlickersTorches']() != 1 or m['dnvLightWindUnnoticeable']() != 1 or m['dnvUpwindDefinition']() != 1 or m['dnvDownwindDefinition']() != 1 or m['dnvCrosswindDefinition']() != 1",
      "note" = "the wind-force scale: strong winds extinguish torches and raise dust, medium winds flicker torches and put out candles, light winds almost unnoticeable, with the upwind/crosswind/downwind direction definitions.",
    } },
  "audit" = {
      "label" = "R510 DSG odor detection audit",
      "comment" = "The DSG odor detection pins the procedure (a Wisdom Check at first encounter, made secretly by the DM, rechecked only when the scent grows very strong or the wind carries it with increased force, not repeated once missed, the full Wisdom score only for easily-noticed odors, the Table 15 cross-reference as the Wisdom modifier, the dash meaning no detection), the dog rules (the check only when the scent would alert them, Wisdom 16 for this check only, the described growl or cringe, the trained reaction, the doubled distance before the negative modifiers), the row definitions (small fires at one foot or less, large fires at 6-8 feet, the oil fires of oil, creosote and coal, the boat-bridge-building conflagration, the sulphur and methane odorous gases, the strong-odor creatures with the 50% lair-scent roll, the mild-odor pigs and herd animals and casually hygienic orcs, the no-odor humans, birds and reptiles, and cooking food), the Table 15 grid (nine sources across the 1-120, 121-360, 361-1000 and 1000-5000 foot bands with the -99 sentinel for the printed dash), the Table 16 wind factors (the strong, medium and light winds against upwind, crosswind and downwind sources in the percent encoding) and the wind definitions (upwind from the source, downwind away, crosswind perpendicular, strong winds extinguishing torches and raising dust, medium flickering torches and extinguishing candles, light almost unnoticeable).",
    },
}
