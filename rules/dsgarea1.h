// =========================================================================================
// Adnd1 - rules/dsgarea1.h
// THE DSG DEEPEARTH AREAS 1-3, R534: printed pp. 78-79 (pdf 79-80) - the
// individual area key opens with the first three areas: Area 1 The Great Lake
// (the fresh cold water fed by rapid streams and meandering rivers; the rocky
// mountainous northern shore with the 1,200-ft maximum depth; the sandy
// eastern and western shores with their fishing villages, natural harbors and
// 400-ft average depth; the southern limestone cliff rising 400 ft and never
// below 100, plunging into the water with no settlements, the 50-ft depth
// sloping to 400 toward the center; the 50-by-120-mile oval on limestone
// bedrock under silt; the trout and salmon, the carnivores and the
// boat-swallowing giant gars; the lonely sirines of the rugged shores and the
// scrags near the lake-bottom center; the fish and mill-wheel resources; and
// the unique features - the 20-ft half-water cave to Area 5, the water-filled
// northern mine shafts, and the wall-of-force-with-permanence spur corridor),
// Area 2 Surface Lands (the temperate terrain sloping upward south to north -
// farmlands, hills, mountains; the harsh winters and heavy rainfall; the
// fortified river-bank trading city; the centaurs, halflings, and the rumored
// enchanted woods of elves, pixies and dryads; the hill dwarves and hill
// giants at odds; the smoldering volcanoes rumored prowled by dragons; the
// farm-and-lumber-and-fish resources with the hill-dwarf gold, silver,
// copper, bloodstone and ruby sales; and the unique features - the city
// dungeon linking sewers to the palace dungeon and to Area 9, the
// thieves-guild and merchant connections, the four-level bandit dungeon with
// its secret passage to Area 4, the half-connecting hill caves to Area 3, and
// the taboo abandoned mine shaft), and Area 3 Upper Caverns (the central
// living-cave limestone maze with plentiful water, the 6-to-8-ft pools, the
// 300-ft-square excavation cap, the 20x10x100-ft largest chamber with its
// 3x2-ft pinches, the wall-of-force watery wall toward the lake; the raiding
// races - troglodytes, goblins, hobgoblins, ogres, trolls and lycanthropes -
// centered in their excavated dungeons; the scavengers, the gibbering
// mouther, greater basilisk and shambling mound, and the wandering beholder
// given a wide berth; the air-water-plants resources; and the unique features
// - the 80-ft troglodyte amphitheater with the fungus-covered war-hero statue
// and its 10,000-gp eye-diamonds, and the 3x1-ft magic pool with its
// pint-per-year drip, the 60-ft infravision, the 2d6-week durations and the
// 30 pints)
// census 457 -> 458.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~9840-9960) with the pdf Acrobat-Capture layer as the second read (idx
// 182-184 = the printed pp. 78-80 windows); the compiled-tables appendix has
// no reprint of this prose. A CLEAN-READ ROUND: both machine reads agree on
// every load-bearing number - the 1,200-ft depth, the 400-ft averages, the
// 50/100/400-ft cliff bands, the 50-by-120-mile oval, the 20-ft cave, the
// four-level dungeon, the 6-to-8-ft pools, the 300-ft cap, the 20x10x100
// chamber with the 3x2 pinches, the 80-ft amphitheater, the 10,000-gp
// diamonds, and the magic-pool numbers (the 3x1-ft size, the pint-per-year
// drip, the 60-ft range, the 2d6 weeks, the 30 pints); the only garbles are
// the standing glyph classes (the djvu "INDIVIDGAL" and "GPPER" header noise,
// non-load-bearing). SEAMS: the R518 water travel (the lake navigation), the
// Monster Manual denizens (the scrags, sirines, beholder and the rest), the
// PHB wall of force and permanence spells, the R521-R522 mining (the mine
// shafts), and the R503 re-grain. A ZERO-FLIP ROUND: the pp. 75-98 Deepearth
// child remains open until the setting lands in full (the R527/R533 precedent
// - the gap report is NOT in the git add). Nothing auto-credits.
//
// A procedural-plus-prose round: no tables pin. The numbers pin as consts per
// the R508 convention - the Great Lake depths and dimensions, the
// surface-lands dungeon levels, and the Upper Caverns geography and
// magic-pool numbers. The geography, denizens, resources and unique-features
// prose pins as bools for all three areas. The R518/MM/PHB/R521-R522/R503
// seams are noted; the Deepearth child stays open; nothing auto-credits.
//
namespace rules {

// ---- the Area 1 Great Lake section ----

// the Great Lake is deepest just off the rocky, mountainous northern shore,
// reaching a maximum depth of some 1,200 feet.
inline int dnarLakeMaxDepthFt()
    { return 1200; }

// the northern half of the Great Lake shore is rocky and mountainous; the
// eastern and western shores are lined with sandy beaches, occasional fishing
// villages, and a few good natural harbors.
inline bool dnarLakeNorthRocky()
    { return true; }

// the average depth of the lake along the sandy eastern and western shores is
// about 400 feet.
inline int dnarLakeAvgDepthFt()
    { return 400; }

// the towering limestone cliff along the southern shore rises as much as 400
// feet above the lake in places.
inline int dnarLakeCliffMaxFt()
    { return 400; }

// the southern escarpment never drops to less than 100 feet above the water
// level, plunging right into the water - no settlements or beaches there.
inline int dnarLakeCliffMinFt()
    { return 100; }

// the water depth at the southern cliff is usually at least 50 feet, sloping
// gradually to about 400 feet toward the center of the lake.
inline int dnarLakeSouthDepthFt()
    { return 50; }

// the roughly oval Great Lake is about 50 miles wide; the entire lake is not
// shown on the map.
inline int dnarLakeWideMiles()
    { return 50; }

// the Great Lake is 120 miles long, its bottom resting on firm limestone
// bedrock covered with several feet of accumulated silt.
inline int dnarLakeLongMiles()
    { return 120; }

// the lake is heavily populated with fish - most varieties of trout and
// freshwater salmon - and large freshwater carnivores are drawn to the
// plentiful food supply; the fishing villages tell common tales of giant gars
// capable of swallowing an entire boat.
inline bool dnarLakeCarnivores()
    { return true; }

// intelligent denizen reports tell of a few lonely sirines along the rugged
// north and south shores with their remote, isolated lairs, and a band of
// freshwater marine trolls - scrags - living near the center of the lake
// bottom, rarely disturbing fishermen and preferring the plentiful lake food
// supplies.
inline bool dnarLakeSirinesScrags()
    { return true; }

// the lake's primary resource is its plentiful fish supply; many communities
// also harness the water flow to turn mill wheels.
inline bool dnarLakeMillWheels()
    { return true; }

// the cave in the southern limestone cliffs is about 20 feet high and equally
// wide, only half filled with water, a gentle current leading into the depths
// of the earth toward Area 5.
inline int dnarLakeCaveHtFt()
    { return 20; }

// several water-filled mine shafts in the mountainous northern shore lead to
// submerged caverns with openings on the bottom of the lake (see Area 2); and
// the small spur of the tunnel to Areas 3 and 4 - an excavated corridor
// cutting directly into the lake bottom - would flood very quickly had its
// excavator not blocked it with a wall of force augmented by permanence.
inline bool dnarLakeMineShafts()
    { return true; }

// ---- the Area 2 Surface Lands section ----

// the lands above Deepearth include all major temperate terrain types,
// generally sloping upward from south to north: fertile farmlands of a
// prosperous surface kingdom with villages, towns and a large city to the
// south, rough rocky hilly wilderness, and the towering crags of a high
// mountain range sealing off the north; harsh winters, mild springs, pleasant
// summers, heavy rainfall.
inline bool dnarSurfaceTerrainFrame()
    { return true; }

// a fortified city on the river banks is the seat of government and a major
// trading center for cargoes transported over land and water; the towns and
// villages are primarily agricultural, each keyed to its own local needs,
// with small bands of bandits in the woods and foothills presenting little
// menace.
inline bool dnarFortifiedCity()
    { return true; }

// besides humans, a small band of centaurs and several halfling villages live
// among the farmland forests; the deepest woods are rumored enchanted and
// populated by elves, pixies and dryads; both dwarves and hill giants live in
// the rocky hills, constantly at odds with raiding and vandalism but no
// pitched battle in many years; the mountains host hardy dwarves and many
// giants, and the far volcanic reaches are rumored prowled by dragons - few
// humans venture there, and fewer still return.
inline bool dnarSurfaceRaces()
    { return true; }

// farming products - grain, milk, meat - are the primary income, with lumber
// harvested from the forests; water is plentiful with rowboats and sailboats
// common, the waters hosting many fish supporting the shore villages; and
// every once in awhile a band of dwarves comes down from the hills to sell
// gold, silver, copper, bloodstones and occasionally rubies - the mine
// locations a closely guarded secret.
inline bool dnarSurfaceResources()
    { return true; }

// at least one sprawling dungeon complex beneath the city connects with a
// natural cavern eventually leading to Area 9, linking the city sewer system
// to the palace dungeon; many catacomb passages connect with the sewers, a
// prominent thieves guild has excavated other connections, and certain
// merchants, wizards and lords have their own underground connections.
inline bool dnarCityDungeonSewers()
    { return true; }

// the bandit dungeon in the forests has four levels, several treasure caches,
// and many horrible monsters; a secret passage in the lowest level leads to
// the Area 4 cavern complex.
inline int dnarBanditDungeonLevels()
    { return 4; }

// natural limestone caves are extremely common among the hills - some very
// shallow with no Deepearth connections, but about half connect together and
// lead the persevering explorer to Area 3, all of the passages natural in
// origin.
inline bool dnarHillCavesHalfConnect()
    { return true; }

// the mountain dwarves created very deep shafts, often discontinued when
// striking water; a few watery connections are large enough for humans to
// pass, leading to exits on the bottom of the large lake; one abandoned shaft
// terminates in a dry cavern - the dwarves will not speak of the reason they
// stopped mining there, and use of that shaft is strictly taboo, though the
// cavern eventually leads to Area 3.
inline bool dnarTabooMineShaft()
    { return true; }

// ---- the Area 3 Upper Caverns section ----

// the Upper Caverns are the central area of a vast network of limestone caves
// - living caves with plentiful water, a virtual maze of twisting, winding
// caverns where cliffs, chasms and constricting passages are very common; the
// caverns entering from the hill region often lead directly in, and several
// longer natural tunnels lead to exits at dwarven mine shafts in the
// mountains.
inline bool dnarUpperMazeLiving()
    { return true; }

// in the Upper Caverns none of the living caves are totally filled with
// water, though occasional pools are six to eight feet deep.
inline int dnarUpperPoolDeepLowFt()
    { return 6; }

// the upper bound of the occasional-pool depth range in the Upper Caverns.
inline int dnarUpperPoolDeepHighFt()
    { return 8; }

// several locations in the Upper Caverns hold dungeons excavated from the
// caves, though none of the excavated areas is larger than 300 feet square.
inline int dnarUpperExcavatedMaxFt()
    { return 300; }

// the largest chamber in the whole Upper Caverns area is not more than 20
// feet wide.
inline int dnarUpperChamberWidFt()
    { return 20; }

// the largest chamber is 10 feet high.
inline int dnarUpperChamberHtFt()
    { return 10; }

// the largest chamber is 100 feet long, each end pinched off by a narrow
// continuation typical of the area.
inline int dnarUpperChamberLongFt()
    { return 100; }

// the pinch continuations of the largest chamber are about three feet high.
inline int dnarUpperPinchHtFt()
    { return 3; }

// the pinch continuations are about two feet wide.
inline int dnarUpperPinchWidFt()
    { return 2; }

// the tunnel leading to the lake ends in a watery wall; only the permanent
// effects of a wall of force prevent the water from flooding much of the
// area.
inline bool dnarUpperWallOfForce()
    { return true; }

// with its relatively easy access to the surface, this part of Deepearth is
// inhabited by creatures that like to raid human settlements - each raiding
// band controlling a small section of caverns, usually centered in an
// excavated dungeon area: troglodytes, goblins, hobgoblins, ogres, trolls and
// lycanthropes, whose individual members fight each other at the slightest
// provocation while the communities coexist relatively peacefully.
inline bool dnarUpperRaiders()
    { return true; }

// a great number of unintelligent monsters roam the passages - giant rats,
// bats, carrion crawlers and other scavengers, plus potent individuals like a
// gibbering mouther, a greater basilisk and a shambling mound; a beholder
// also wanders the tunnels taking what it wants - the most powerful monster
// in the area, given a wide berth by all others.
inline bool dnarUpperMonstersBeholder()
    { return true; }

// the Upper Caverns have plentiful supplies of air and water, no evidence of
// any kind of mineral wealth, and a variety of underground plants - lichens,
// molds and fungi - providing the basic element in the food chain.
inline bool dnarUpperAirWaterPlants()
    { return true; }

// the troglodytes control the largest collection of dungeon and cavern areas,
// centered on the amphitheater with its large fungus-covered, vaguely
// humanoid statue worshipped as their deity - in fact a quite unremarkable
// sculpture of a human war hero, each eye holding a massive diamond
// completely covered by the spreading fungus.
inline bool dnarTroglodyteStatue()
    { return true; }

// the troglodytes center their holdings on a large, circular amphitheater
// about 80 feet in diameter.
inline int dnarAmphitheaterDiaFt()
    { return 80; }

// each eye of the fungus-covered statue the troglodytes worship holds a
// massive diamond worth 10,000 gp, completely covered by the spreading
// fungus.
inline int dnarStatueDiamondGp()
    { return 10000; }

// the magic pool is only three feet wide.
inline int dnarPoolWidFt()
    { return 3; }

// the magic pool is one foot deep.
inline int dnarPoolDeepFt()
    { return 1; }

// water drips slowly into the magic pool from a stalactite at the rate of one
// pint per year, gaining an enchantment during the process - becoming a
// potion of infravision.
inline int dnarPoolDripPintsPerYear()
    { return 1; }

// a character without infravision who drinks a pint of the magic pool water
// gains the ability with a 60-foot range.
inline int dnarPoolInfraRangeFt()
    { return 60; }

// the infravision gained or lost from the magic pool lasts 2d6 weeks.
inline int dnarPoolInfraWeeksDice()
    { return 2; }

// the duration die of the magic-pool effect is a d6, two of them; characters
// with infravision who drink lose the ability for a similar time.
inline int dnarPoolInfraWeeksSides()
    { return 6; }

// there are 30 pints of water in the magic pool; stored in an airtight
// container it keeps indefinitely.
inline int dnarPoolPints()
    { return 30; }

}   // namespace rules
