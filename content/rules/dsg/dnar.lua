-- dnar: promoted from tools/spec_r534.json (the THE DSG DEEPEARTH AREAS 1-3, R534: printed pp. 78-79 (pdf 79-80) - the individual area key opens with the first three areas: Area 1 The Great Lake (the fresh cold water fed by rapid streams and meandering rivers; the rocky mountainous northern shore with the 1,200-ft maximum depth; the sandy eastern and western shores with their fishing villages, natural harbors and 400-ft average depth; the southern limestone cliff rising 400 ft and never below 100, plunging into the water with no settlements, the 50-ft depth sloping to 400 toward the center; the 50-by-120-mile oval on limestone bedrock under silt; the trout and salmon, the carnivores and the boat-swallowing giant gars; the lonely sirines of the rugged shores and the scrags near the lake-bottom center; the fish and mill-wheel resources; and the unique features - the 20-ft half-water cave to Area 5, the water-filled northern mine shafts, and the wall-of-force-with-permanence spur corridor), Area 2 Surface Lands (the temperate terrain sloping upward south to north - farmlands, hills, mountains; the harsh winters and heavy rainfall; the fortified river-bank trading city; the centaurs, halflings, and the rumored enchanted woods of elves, pixies and dryads; the hill dwarves and hill giants at odds; the smoldering volcanoes rumored prowled by dragons; the farm-and-lumber-and-fish resources with the hill-dwarf gold, silver, copper, bloodstone and ruby sales; and the unique features - the city dungeon linking sewers to the palace dungeon and to Area 9, the thieves-guild and merchant connections, the four-level bandit dungeon with its secret passage to Area 4, the half-connecting hill caves to Area 3, and the taboo abandoned mine shaft), and Area 3 Upper Caverns (the central living-cave limestone maze with plentiful water, the 6-to-8-ft pools, the 300-ft-square excavation cap, the 20x10x100-ft largest chamber with its 3x2-ft pinches, the wall-of-force watery wall toward the lake; the raiding races - troglodytes, goblins, hobgoblins, ogres, trolls and lycanthropes - centered in their excavated dungeons; the scavengers, the gibbering mouther, greater basilisk and shambling mound, and the wandering beholder given a wide berth; the air-water-plants resources; and the unique features - the 80-ft troglodyte amphitheater with the fungus-covered war-hero statue and its 10,000-gp eye-diamonds, and the 3x1-ft magic pool with its pint-per-year drip, the 60-ft infravision, the 2d6-week durations and the 30 pints));
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 534,
  "prefix" = "dnar",
  "banner" = {
      "title" = "THE DSG DEEPEARTH AREAS 1-3, R534: printed pp. 78-79 (pdf 79-80) - the individual area key opens with the first three areas: Area 1 The Great Lake (the fresh cold water fed by rapid streams and meandering rivers; the rocky mountainous northern shore with the 1,200-ft maximum depth; the sandy eastern and western shores with their fishing villages, natural harbors and 400-ft average depth; the southern limestone cliff rising 400 ft and never below 100, plunging into the water with no settlements, the 50-ft depth sloping to 400 toward the center; the 50-by-120-mile oval on limestone bedrock under silt; the trout and salmon, the carnivores and the boat-swallowing giant gars; the lonely sirines of the rugged shores and the scrags near the lake-bottom center; the fish and mill-wheel resources; and the unique features - the 20-ft half-water cave to Area 5, the water-filled northern mine shafts, and the wall-of-force-with-permanence spur corridor), Area 2 Surface Lands (the temperate terrain sloping upward south to north - farmlands, hills, mountains; the harsh winters and heavy rainfall; the fortified river-bank trading city; the centaurs, halflings, and the rumored enchanted woods of elves, pixies and dryads; the hill dwarves and hill giants at odds; the smoldering volcanoes rumored prowled by dragons; the farm-and-lumber-and-fish resources with the hill-dwarf gold, silver, copper, bloodstone and ruby sales; and the unique features - the city dungeon linking sewers to the palace dungeon and to Area 9, the thieves-guild and merchant connections, the four-level bandit dungeon with its secret passage to Area 4, the half-connecting hill caves to Area 3, and the taboo abandoned mine shaft), and Area 3 Upper Caverns (the central living-cave limestone maze with plentiful water, the 6-to-8-ft pools, the 300-ft-square excavation cap, the 20x10x100-ft largest chamber with its 3x2-ft pinches, the wall-of-force watery wall toward the lake; the raiding races - troglodytes, goblins, hobgoblins, ogres, trolls and lycanthropes - centered in their excavated dungeons; the scavengers, the gibbering mouther, greater basilisk and shambling mound, and the wandering beholder given a wide berth; the air-water-plants resources; and the unique features - the 80-ft troglodyte amphitheater with the fungus-covered war-hero statue and its 10,000-gp eye-diamonds, and the 3x1-ft magic pool with its pint-per-year drip, the 60-ft infravision, the 2d6-week durations and the 30 pints)",
      "provenance" = "the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf = printed + 1; the text read from the IA djvu OCR (djvu.txt lines ~9840-9960) with the pdf Acrobat-Capture layer as the second read (idx 182-184 = the printed pp. 78-80 windows); the compiled-tables appendix has no reprint of this prose. A CLEAN-READ ROUND: both machine reads agree on every load-bearing number - the 1,200-ft depth, the 400-ft averages, the 50/100/400-ft cliff bands, the 50-by-120-mile oval, the 20-ft cave, the four-level dungeon, the 6-to-8-ft pools, the 300-ft cap, the 20x10x100 chamber with the 3x2 pinches, the 80-ft amphitheater, the 10,000-gp diamonds, and the magic-pool numbers (the 3x1-ft size, the pint-per-year drip, the 60-ft range, the 2d6 weeks, the 30 pints); the only garbles are the standing glyph classes (the djvu \"INDIVIDGAL\" and \"GPPER\" header noise, non-load-bearing). SEAMS: the R518 water travel (the lake navigation), the Monster Manual denizens (the scrags, sirines, beholder and the rest), the PHB wall of force and permanence spells, the R521-R522 mining (the mine shafts), and the R503 re-grain. A ZERO-FLIP ROUND: the pp. 75-98 Deepearth child remains open until the setting lands in full (the R527/R533 precedent - the gap report is NOT in the git add). Nothing auto-credits.",
      "sentinel" = "A procedural-plus-prose round: no tables pin. The numbers pin as consts per the R508 convention - the Great Lake depths and dimensions, the surface-lands dungeon levels, and the Upper Caverns geography and magic-pool numbers. The geography, denizens, resources and unique-features prose pins as bools for all three areas. The R518/MM/PHB/R521-R522/R503 seams are noted; the Deepearth child stays open; nothing auto-credits.",
    },
  "consts" = { {
      "name" = "dnarLakeMaxDepthFt",
      "value" = 1200,
      "comment" = "the Great Lake is deepest just off the rocky, mountainous northern shore, reaching a maximum depth of some 1,200 feet.",
    }, {
      "name" = "dnarLakeAvgDepthFt",
      "value" = 400,
      "comment" = "the average depth of the lake along the sandy eastern and western shores is about 400 feet.",
    }, {
      "name" = "dnarLakeCliffMaxFt",
      "value" = 400,
      "comment" = "the towering limestone cliff along the southern shore rises as much as 400 feet above the lake in places.",
    }, {
      "name" = "dnarLakeCliffMinFt",
      "value" = 100,
      "comment" = "the southern escarpment never drops to less than 100 feet above the water level, plunging right into the water - no settlements or beaches there.",
    }, {
      "name" = "dnarLakeSouthDepthFt",
      "value" = 50,
      "comment" = "the water depth at the southern cliff is usually at least 50 feet, sloping gradually to about 400 feet toward the center of the lake.",
    }, {
      "name" = "dnarLakeWideMiles",
      "value" = 50,
      "comment" = "the roughly oval Great Lake is about 50 miles wide; the entire lake is not shown on the map.",
    }, {
      "name" = "dnarLakeLongMiles",
      "value" = 120,
      "comment" = "the Great Lake is 120 miles long, its bottom resting on firm limestone bedrock covered with several feet of accumulated silt.",
    }, {
      "name" = "dnarLakeCaveHtFt",
      "value" = 20,
      "comment" = "the cave in the southern limestone cliffs is about 20 feet high and equally wide, only half filled with water, a gentle current leading into the depths of the earth toward Area 5.",
    }, {
      "name" = "dnarBanditDungeonLevels",
      "value" = 4,
      "comment" = "the bandit dungeon in the forests has four levels, several treasure caches, and many horrible monsters; a secret passage in the lowest level leads to the Area 4 cavern complex.",
    }, {
      "name" = "dnarUpperPoolDeepLowFt",
      "value" = 6,
      "comment" = "in the Upper Caverns none of the living caves are totally filled with water, though occasional pools are six to eight feet deep.",
    }, {
      "name" = "dnarUpperPoolDeepHighFt",
      "value" = 8,
      "comment" = "the upper bound of the occasional-pool depth range in the Upper Caverns.",
    }, {
      "name" = "dnarUpperExcavatedMaxFt",
      "value" = 300,
      "comment" = "several locations in the Upper Caverns hold dungeons excavated from the caves, though none of the excavated areas is larger than 300 feet square.",
    }, {
      "name" = "dnarUpperChamberWidFt",
      "value" = 20,
      "comment" = "the largest chamber in the whole Upper Caverns area is not more than 20 feet wide.",
    }, {
      "name" = "dnarUpperChamberHtFt",
      "value" = 10,
      "comment" = "the largest chamber is 10 feet high.",
    }, {
      "name" = "dnarUpperChamberLongFt",
      "value" = 100,
      "comment" = "the largest chamber is 100 feet long, each end pinched off by a narrow continuation typical of the area.",
    }, {
      "name" = "dnarUpperPinchHtFt",
      "value" = 3,
      "comment" = "the pinch continuations of the largest chamber are about three feet high.",
    }, {
      "name" = "dnarUpperPinchWidFt",
      "value" = 2,
      "comment" = "the pinch continuations are about two feet wide.",
    }, {
      "name" = "dnarAmphitheaterDiaFt",
      "value" = 80,
      "comment" = "the troglodytes center their holdings on a large, circular amphitheater about 80 feet in diameter.",
    }, {
      "name" = "dnarStatueDiamondGp",
      "value" = 10000,
      "comment" = "each eye of the fungus-covered statue the troglodytes worship holds a massive diamond worth 10,000 gp, completely covered by the spreading fungus.",
    }, {
      "name" = "dnarPoolWidFt",
      "value" = 3,
      "comment" = "the magic pool is only three feet wide.",
    }, {
      "name" = "dnarPoolDeepFt",
      "value" = 1,
      "comment" = "the magic pool is one foot deep.",
    }, {
      "name" = "dnarPoolDripPintsPerYear",
      "value" = 1,
      "comment" = "water drips slowly into the magic pool from a stalactite at the rate of one pint per year, gaining an enchantment during the process - becoming a potion of infravision.",
    }, {
      "name" = "dnarPoolInfraRangeFt",
      "value" = 60,
      "comment" = "a character without infravision who drinks a pint of the magic pool water gains the ability with a 60-foot range.",
    }, {
      "name" = "dnarPoolInfraWeeksDice",
      "value" = 2,
      "comment" = "the infravision gained or lost from the magic pool lasts 2d6 weeks.",
    }, {
      "name" = "dnarPoolInfraWeeksSides",
      "value" = 6,
      "comment" = "the duration die of the magic-pool effect is a d6, two of them; characters with infravision who drink lose the ability for a similar time.",
    }, {
      "name" = "dnarPoolPints",
      "value" = 30,
      "comment" = "there are 30 pints of water in the magic pool; stored in an airtight container it keeps indefinitely.",
    } },
  "bools" = { {
      "name" = "dnarLakeNorthRocky",
      "value" = true,
      "comment" = "the northern half of the Great Lake shore is rocky and mountainous; the eastern and western shores are lined with sandy beaches, occasional fishing villages, and a few good natural harbors.",
    }, {
      "name" = "dnarLakeCarnivores",
      "value" = true,
      "comment" = "the lake is heavily populated with fish - most varieties of trout and freshwater salmon - and large freshwater carnivores are drawn to the plentiful food supply; the fishing villages tell common tales of giant gars capable of swallowing an entire boat.",
    }, {
      "name" = "dnarLakeSirinesScrags",
      "value" = true,
      "comment" = "intelligent denizen reports tell of a few lonely sirines along the rugged north and south shores with their remote, isolated lairs, and a band of freshwater marine trolls - scrags - living near the center of the lake bottom, rarely disturbing fishermen and preferring the plentiful lake food supplies.",
    }, {
      "name" = "dnarLakeMillWheels",
      "value" = true,
      "comment" = "the lake's primary resource is its plentiful fish supply; many communities also harness the water flow to turn mill wheels.",
    }, {
      "name" = "dnarLakeMineShafts",
      "value" = true,
      "comment" = "several water-filled mine shafts in the mountainous northern shore lead to submerged caverns with openings on the bottom of the lake (see Area 2); and the small spur of the tunnel to Areas 3 and 4 - an excavated corridor cutting directly into the lake bottom - would flood very quickly had its excavator not blocked it with a wall of force augmented by permanence.",
    }, {
      "name" = "dnarSurfaceTerrainFrame",
      "value" = true,
      "comment" = "the lands above Deepearth include all major temperate terrain types, generally sloping upward from south to north: fertile farmlands of a prosperous surface kingdom with villages, towns and a large city to the south, rough rocky hilly wilderness, and the towering crags of a high mountain range sealing off the north; harsh winters, mild springs, pleasant summers, heavy rainfall.",
    }, {
      "name" = "dnarFortifiedCity",
      "value" = true,
      "comment" = "a fortified city on the river banks is the seat of government and a major trading center for cargoes transported over land and water; the towns and villages are primarily agricultural, each keyed to its own local needs, with small bands of bandits in the woods and foothills presenting little menace.",
    }, {
      "name" = "dnarSurfaceRaces",
      "value" = true,
      "comment" = "besides humans, a small band of centaurs and several halfling villages live among the farmland forests; the deepest woods are rumored enchanted and populated by elves, pixies and dryads; both dwarves and hill giants live in the rocky hills, constantly at odds with raiding and vandalism but no pitched battle in many years; the mountains host hardy dwarves and many giants, and the far volcanic reaches are rumored prowled by dragons - few humans venture there, and fewer still return.",
    }, {
      "name" = "dnarSurfaceResources",
      "value" = true,
      "comment" = "farming products - grain, milk, meat - are the primary income, with lumber harvested from the forests; water is plentiful with rowboats and sailboats common, the waters hosting many fish supporting the shore villages; and every once in awhile a band of dwarves comes down from the hills to sell gold, silver, copper, bloodstones and occasionally rubies - the mine locations a closely guarded secret.",
    }, {
      "name" = "dnarCityDungeonSewers",
      "value" = true,
      "comment" = "at least one sprawling dungeon complex beneath the city connects with a natural cavern eventually leading to Area 9, linking the city sewer system to the palace dungeon; many catacomb passages connect with the sewers, a prominent thieves guild has excavated other connections, and certain merchants, wizards and lords have their own underground connections.",
    }, {
      "name" = "dnarHillCavesHalfConnect",
      "value" = true,
      "comment" = "natural limestone caves are extremely common among the hills - some very shallow with no Deepearth connections, but about half connect together and lead the persevering explorer to Area 3, all of the passages natural in origin.",
    }, {
      "name" = "dnarTabooMineShaft",
      "value" = true,
      "comment" = "the mountain dwarves created very deep shafts, often discontinued when striking water; a few watery connections are large enough for humans to pass, leading to exits on the bottom of the large lake; one abandoned shaft terminates in a dry cavern - the dwarves will not speak of the reason they stopped mining there, and use of that shaft is strictly taboo, though the cavern eventually leads to Area 3.",
    }, {
      "name" = "dnarUpperMazeLiving",
      "value" = true,
      "comment" = "the Upper Caverns are the central area of a vast network of limestone caves - living caves with plentiful water, a virtual maze of twisting, winding caverns where cliffs, chasms and constricting passages are very common; the caverns entering from the hill region often lead directly in, and several longer natural tunnels lead to exits at dwarven mine shafts in the mountains.",
    }, {
      "name" = "dnarUpperWallOfForce",
      "value" = true,
      "comment" = "the tunnel leading to the lake ends in a watery wall; only the permanent effects of a wall of force prevent the water from flooding much of the area.",
    }, {
      "name" = "dnarUpperRaiders",
      "value" = true,
      "comment" = "with its relatively easy access to the surface, this part of Deepearth is inhabited by creatures that like to raid human settlements - each raiding band controlling a small section of caverns, usually centered in an excavated dungeon area: troglodytes, goblins, hobgoblins, ogres, trolls and lycanthropes, whose individual members fight each other at the slightest provocation while the communities coexist relatively peacefully.",
    }, {
      "name" = "dnarUpperMonstersBeholder",
      "value" = true,
      "comment" = "a great number of unintelligent monsters roam the passages - giant rats, bats, carrion crawlers and other scavengers, plus potent individuals like a gibbering mouther, a greater basilisk and a shambling mound; a beholder also wanders the tunnels taking what it wants - the most powerful monster in the area, given a wide berth by all others.",
    }, {
      "name" = "dnarUpperAirWaterPlants",
      "value" = true,
      "comment" = "the Upper Caverns have plentiful supplies of air and water, no evidence of any kind of mineral wealth, and a variety of underground plants - lichens, molds and fungi - providing the basic element in the food chain.",
    }, {
      "name" = "dnarTroglodyteStatue",
      "value" = true,
      "comment" = "the troglodytes control the largest collection of dungeon and cavern areas, centered on the amphitheater with its large fungus-covered, vaguely humanoid statue worshipped as their deity - in fact a quite unremarkable sculpture of a human war hero, each eye holding a massive diamond completely covered by the spreading fungus.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dnarLakeMaxDepthFt']() != 1200 or m['dnarLakeAvgDepthFt']() != 400 or m['dnarLakeCliffMaxFt']() != 400 or m['dnarLakeCliffMinFt']() != 100 or m['dnarLakeSouthDepthFt']() != 50 or m['dnarLakeWideMiles']() != 50 or m['dnarLakeLongMiles']() != 120 or m['dnarLakeCaveHtFt']() != 20",
      "note" = "the Great Lake numbers: the 1,200-ft maximum depth, the 400-ft average, the 400/100-ft cliff, the 50-ft southern depth, the 50-by-120-mile oval, the 20-ft cave.",
    }, {
      "expr" = "m['dnarBanditDungeonLevels']() != 4 or m['dnarUpperExcavatedMaxFt']() != 300",
      "note" = "the surface and upper-cavern excavation numbers: the four-level bandit dungeon, the 300-ft-square excavation cap.",
    }, {
      "expr" = "m['dnarUpperPoolDeepLowFt']() != 6 or m['dnarUpperPoolDeepHighFt']() != 8 or m['dnarUpperChamberWidFt']() != 20 or m['dnarUpperChamberHtFt']() != 10 or m['dnarUpperChamberLongFt']() != 100 or m['dnarUpperPinchHtFt']() != 3 or m['dnarUpperPinchWidFt']() != 2",
      "note" = "the Upper Caverns geography: the 6-to-8-ft pools, the 20x10x100-ft largest chamber, the 3x2-ft pinches.",
    }, {
      "expr" = "m['dnarAmphitheaterDiaFt']() != 80 or m['dnarStatueDiamondGp']() != 10000 or m['dnarPoolWidFt']() != 3 or m['dnarPoolDeepFt']() != 1 or m['dnarPoolDripPintsPerYear']() != 1 or m['dnarPoolInfraRangeFt']() != 60 or m['dnarPoolInfraWeeksDice']() != 2 or m['dnarPoolInfraWeeksSides']() != 6 or m['dnarPoolPints']() != 30",
      "note" = "the troglodyte amphitheater, the statue diamonds, and the magic pool: the 80-ft diameter, the 10,000-gp diamonds, the 3x1-ft pool, the pint-per-year drip, the 60-ft infravision, the 2d6 weeks, the 30 pints.",
    }, {
      "expr" = "m['dnarLakeCarnivores']() != 1 or m['dnarLakeSirinesScrags']() != 1 or m['dnarLakeMillWheels']() != 1 or m['dnarLakeMineShafts']() != 1",
      "note" = "the Great Lake prose: the carnivores and giant gars, the sirines and scrags, the mill wheels, the mine shafts and the wall of force.",
    }, {
      "expr" = "m['dnarSurfaceTerrainFrame']() != 1 or m['dnarFortifiedCity']() != 1 or m['dnarSurfaceRaces']() != 1 or m['dnarSurfaceResources']() != 1 or m['dnarCityDungeonSewers']() != 1 or m['dnarHillCavesHalfConnect']() != 1 or m['dnarTabooMineShaft']() != 1",
      "note" = "the Surface Lands prose: the terrain frame, the fortified city, the races, the resources, the city dungeon and sewers, the half-connecting hill caves, the taboo mine shaft.",
    }, {
      "expr" = "m['dnarUpperMazeLiving']() != 1 or m['dnarUpperWallOfForce']() != 1 or m['dnarUpperRaiders']() != 1 or m['dnarUpperMonstersBeholder']() != 1 or m['dnarUpperAirWaterPlants']() != 1 or m['dnarTroglodyteStatue']() != 1",
      "note" = "the Upper Caverns prose: the living maze, the wall of force, the raiding races, the monsters and the beholder, the air-water-plants resources, the troglodyte statue.",
    } },
  "audit" = {
      "label" = "R534 DSG Deepearth areas 1-3 audit",
      "comment" = "The DSG Deepearth areas 1-3 pin Area 1 (the Great Lake with its depths, cliff, denizens and the wall-of-force spur), Area 2 (the surface lands with the city sewers, the four-level bandit dungeon, the half-connecting hill caves and the taboo shaft), and Area 3 (the Upper Caverns with the raiding races, the beholder, the troglodyte amphitheater and the magic infravision pool).",
    },
}
