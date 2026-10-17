// =========================================================================================
// Adnd1 - rules/dsgarea7.h
// THE DSG DEEPEARTH AREAS 14-15, R540: printed pp. 86-88 (pdf 87-89) - the
// individual area key crosses the reclaimed lakebed and the great water: Area
// 14 Reclaimed Caverns (the former subterranean lake almost completely filled
// with water, drained only by the diligent pech miners' blocked waterways -
// the two north inflows and south outflow continuations; the Area 5 river
// made dangerous by its 500-foot waterfall into a deep pool, then running
// placid beneath about six feet of airspace; the eastern river diving
// underground at the base of a mountain waterfall plunging several thousand
// feet through a sinkhole, rapid all the way to Area 14 but keeping a 10-foot
// minimum airspace and a navigable sinkhole access; the three long narrow
// parallel caves east-west, each opening onto the river and united by
// connecting passages; the heroic walls-of-stone dikes holding the water out
// while small streams still flow; the pech bridge over the eastern river at
// the middle cavern's end, joining the partially excavated 8-by-12-foot
// descending cavern of many miles; the water-polished uniformly smooth
// floors, walls and ceilings devoid of formations; the well-organized
// 300-miner community at the middle cavern's center with its iron and copper
// deposits; the monster roster - scrags, shambling mounds, a gibbering
// mouther, cave crickets, throat leeches, ropers, an owl bear, rust monsters
// and cockatrices; the Area 15 kuo-toan sabotage war - dikes damaged, rivers
// diverted, 20-to-25-strong war parties every few months, always defeated but
// never ceasing; the fanatically guarded copper and iron ore stockpiles; and
// the engineering marvels - the drains and centrifugal pump powered by the
// bridge-side giant water wheel, the lever-shifted ventilation over the
// coal-burning smelting plant and forge venting through a one-foot aperture
// to a remote mountain valley, and the stone town with its buildings stacked
// three or four deep and its ore wagons blocking the avenues), and Area 15
// the Upper Lake of Deepearth (the almost completely water-filled chamber on
// its rock walls and columns, the level a dozen or more feet short of the
// ceiling, boat-traversable over most of its extent; the west shoreline shelf
// - 10 to 400 feet wide, the only dry land, reached through the partly carved
// dry tunnel from Area 6 with its intelligent-built stone piers and the 50%
// chance of 1d6 moored longboats; the cold still waters 10 to 100 feet deep,
// marred only where the twin Area 14 rivers enter; the center drain hole
// matching its outflow to the inflow, regulated by the kuo-toa and their
// boulder works; the great kuo-toan numbers and the blind fish of the inky
// depths; the domes over food-raising, quarters, hatcheries, government and
// recreation with their breathable air pockets where escape is virtually
// impossible; the giant catfish, pike, gar, lamprey, trout, perch and salmon,
// the water nagas, giant otters, giant crabs, giant snapping turtles, scrags
// and lacedons; the aboleth - perhaps the most purely evil denizens in all
// Deepearth, avoiding the kuo-toa but seizing all others as slaves; the
// aquatic fungi and brown algae with no minerals known; and the domed city by
// the drain - six hexagonal major domes, 150 feet across and 50 high with 20
// feet of air, their corridors and rooms nested around the swim-through
// elevator holes)
// census 463 -> 464.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~11005-11253) with the pdf Acrobat-Capture layer as the second read (idx
// 396-400 = the printed pp. 86-89 windows, with idx396's stream emitting the
// p. 87 area 14 body in its first block before the p. 86 tail blocks - a
// page-block order anomaly, all text present); the compiled-tables appendix
// has no reprint of this prose. A CLEAN-READ ROUND: both machine reads agree
// on every load-bearing number - the 500-ft waterfall, the six-foot and
// ten-foot airspaces, the three caves, the 8x12-ft bridge cavern, the 300
// miners, the 20-to-25 war parties, the one-foot vent, the three-or-four-deep
// stacking, the 50% longboat chance, the 10/400-ft shelf, the 10/100-ft
// depths, and the six 150/50-ft domes with 20 ft of air; the garbles settled
// cross-read (the djvu '5096' for the capture's 50%, the capture 'ld6' for
// the djvu's 1d6). SEAMS: the R518 water travel (the river routes and the
// navigable sinkhole), the Monster Manual denizens (the pech, kuo-toa,
// aboleth, kraken-less lake fauna and the monster roster), the PHB wall of
// stone, the R521-R522 mining (the iron and copper works), and the R503
// re-grain. A ZERO-FLIP ROUND: the pp. 75-98 Deepearth child remains open
// until the setting lands in full (the R527/R533-R539 precedent - the gap
// report is NOT in the git add). Nothing auto-credits.
//
// A procedural-plus-prose round: no tables pin. The numbers pin as consts per
// the R508 convention - the waterfall and airspace feet, the cave and dome
// counts, the bridge cavern's 8x12, the 300 miners, the war-party bounds, the
// vent aperture and stacking depths, the longboat chance and dice, the shelf
// and depth bounds, and the dome dimensions with their air cap, with the 1d6
// dice pinned as a count-and-sides pair. The geography, denizens, resources
// and unique-features prose pins as bools for both areas. The
// water-travel/MM/PHB/mining/R503 seams are noted; the Deepearth child stays
// open; nothing auto-credits.
//
namespace rules {

// ---- the Area 14 Reclaimed Caverns section ----

// these caverns were once part of a subterranean lake and were almost
// completely filled with water; only the diligent efforts of a group of pech
// miners blocked off the water flow and enabled air to fill the bulk of this
// area - accessible only through the two waterways flowing in on the north
// side and the continuations of these streams flowing out from the south.
inline bool dnaiLakeReclaimed()
    { return true; }

// the course of the river flowing from Area 5 is made dangerous by a 500-foot
// waterfall that plunges into a deep pool before resuming a more placid
// journey downstream through Area 14.
inline int dnaiFallsFt()
    { return 500; }

// the latter part of the Area 5 river's journey runs through a cavern that
// allows about six feet of airspace over the surface of the river.
inline int dnaiAirspaceWestFt()
    { return 6; }

// the easternmost river goes underground at the base of a huge mountain
// waterfall, plunging several thousand feet from an isolated gorge to
// disappear through a sinkhole and begin a hidden course; since the sinkhole
// allows fairly easy access to the water below, this river provides a
// navigable means of reaching Area 14.
inline bool dnaiEastRiverRoute()
    { return true; }

// the easternmost river, rapid from its first moments underground, here has
// airspace over the water of a minimum of 10 feet high.
inline int dnaiAirspaceEastFt()
    { return 10; }

// the area itself comprises three long, narrow caves running parallel along
// an east-west access, each opening onto the river and united by numerous
// connecting passages.
inline int dnaiCaveCount()
    { return 3; }

// by dint of heroic applications of walls of stone the pech have built dikes
// to keep the water out of the three caverns; small streams still flow
// through but menace no one, and the area provides both dry and river routes
// deeper into the earth.
inline bool dnaiPechDikes()
    { return true; }

// the bridge over the easternmost river connects with a partially excavated,
// partially natural cavern that descends slowly over many miles; this cavern
// is eight feet high.
inline int dnaiBridgeCavernHtFt()
    { return 8; }

// the descending bridge cavern is 12 feet wide.
inline int dnaiBridgeCavernWidFt()
    { return 12; }

// because these caves were filled with water until relatively recently
// (geologically speaking) they are devoid of common cave formations - floors,
// walls and ceilings almost uniformly smooth, polished by the action of water
// through many centuries.
inline bool dnaiSmoothCaves()
    { return true; }

// the pech have created a well-organized community in the center of the
// middle cavern; a total of about 300 of these industrious miners live here.
inline int dnaiPechCount()
    { return 300; }

// with their unerring instinct for potential mining sites the pech opened the
// caverns to mining and have profited - major deposits of iron and copper
// have been discovered here, with mining parties journeying from the central
// community and returning with loads of ore; all sorts of fungi now thrive in
// the remote corners.
inline bool dnaiPechMining()
    { return true; }

// an assortment of monsters roams these caverns, living off the fungi and any
// prey they can catch: a small group of marine trolls (scrags), several
// shambling mounds, a gibbering mouther, many cave crickets, throat leeches,
// ropers, an owl bear, rust monsters, and cockatrices.
inline bool dnaiMonsterRoster()
    { return true; }

// the kuo-toan war parties from Area 15 generally number about 20-25
// individuals (the low bound).
inline int dnaiKuoPartyLow()
    { return 20; }

// the kuo-toan war parties generally number 20-25 individuals (the high
// bound), attacking any creatures they run into but especially seeking out
// the pech.
inline int dnaiKuoPartyHigh()
    { return 25; }

// the area is subject to the depredations of the Area 15 kuo-toa, who would
// like to see the entire area filled with water again - they regularly
// attempt to sabotage the pech efforts by damaging the dikes or diverting the
// river to flood the caverns; the men-fish have always been defeated in these
// conflicts but send up another war party every few months, forcing the pech
// to constantly maintain their guard.
inline bool dnaiKuoRaids()
    { return true; }

// the rivers flowing into the region have enough airspace to maintain a
// constant supply of fresh air; the pech operate a number of large-scale
// mining operations and have stockpiled large amounts of copper and iron ore
// which, beyond limited amounts for tools and weapons, they seem to have
// little use for - nonetheless they guard their hoard with fanatical
// dedication.
inline bool dnaiPechHoard()
    { return true; }

// the pech have built an elaborate pumping system relying on drains in the
// low spots of each of the three main caverns and a huge centrifugal pump
// diverting water to Area 15 - powered by a giant water wheel where the
// bridge crosses the eastern river, spinning a large fan in a drainage pipe
// that can move an incredible amount of water when the rivers run high.
inline bool dnaiPumpingPlant()
    { return true; }

// simply by shifting a large lever the pump can activate a ventilation system
// over the pech smelting plant and forge, located in the center of their
// small stone community - it can burn great quantities of coal in a few
// hours, its smoke pulled through a vent to exit into a remote mountain
// valley.
inline bool dnaiSmeltingForge()
    { return true; }

// when the pech smelting plant operates, the pumping system pulls the smoke
// through a vent to be released on the surface, eventually exiting through a
// one-foot-wide aperture into a remote mountain valley.
inline int dnaiVentApertureFt()
    { return 1; }

// the pech community's stone buildings tend to be stacked three or four deep
// (the low bound).
inline int dnaiStackLow()
    { return 3; }

// the stone buildings are stacked three or four deep, with narrow winding
// alleys providing access (the high bound).
inline int dnaiStackHigh()
    { return 4; }

// the pech community is well-organized and neat - stone buildings, large
// stone wagons used for pulling loads of ore, several parked about the
// community at all times, often blocking one or more important avenues.
inline bool dnaiStoneTown()
    { return true; }

// ---- the Area 15 Upper Lake section ----

// this subterranean chamber is almost completely water-filled; walls and
// columns of rock support the ceiling over mostly open water, the level
// falling a dozen or more feet short of the ceiling in most places though
// some ceiling drops to or below water level - boat travel is possible over
// most of the Upper Lake.
inline bool dnaiLakeChamber()
    { return true; }

// at the west end lies a shoreline reached through a dry tunnel branching
// down from Area 6 - partly natural caverns, much of it carved by intelligent
// denizens, serving as one of the major avenues to the surface world, with
// stone piers obviously built by intelligent creatures.
inline bool dnaiWestShoreline()
    { return true; }

// there is a 50% chance that 1d6 longboats are moored at the stone piers of
// the west shoreline at any time.
inline int dnaiLongboatPct()
    { return 50; }

// the moored longboats number 1d6 (the die count).
inline int dnaiLongboatDice()
    { return 1; }

// the moored longboats number 1d6 (the die sides).
inline int dnaiLongboatSides()
    { return 6; }

// the dry-land shoreline shelf of rock ranges from 10 to 400 feet wide (the
// low bound) - the only part of the entire chamber where one can walk on dry
// land.
inline int dnaiShelfLowFt()
    { return 10; }

// the shoreline shelf ranges from 10 to 400 feet wide (the high bound).
inline int dnaiShelfHighFt()
    { return 400; }

// the lake's depth varies from 10 to 100 feet (the low bound).
inline int dnaiDepthLowFt()
    { return 10; }

// the lake's depth varies from 10 to 100 feet (the high bound).
inline int dnaiDepthHighFt()
    { return 100; }

// the lake's waters are cold and mostly still, marred by turbulence only
// where the twin rivers from Area 14 enter; in the depths near the center a
// small hole drains water to the lower levels of Deepearth, its outflow
// almost perfectly matching the inflow so the level remains fairly constant.
inline bool dnaiLakeDrain()
    { return true; }

// the kuo-toa dwell here in great numbers along with many varieties of blind
// fish in the inky waters; they have built a number of great domes over
// food-raising, living quarters, fingerling hatcheries, government centers
// and recreation - mostly water-filled but each holding a small pocket of
// breathable air at the top, where air-breathing prisoners are left since
// escape is virtually impossible.
inline bool dnaiKuoDomestead()
    { return true; }

// giant catfish, giant pike, giant gar, lamprey and numerous trout, perch and
// salmon lurk in the depths, along with water nagas, giant otters, giant
// crabs, giant snapping turtles, scrags and lacedons (marine ghouls).
inline bool dnaiLakeFauna()
    { return true; }

// aboleth may also be encountered in the depths of the lake - perhaps the
// most purely evil denizens in all of Deepearth; found in small groups, they
// actively avoid the kuo-toa, but all other creatures are fair game: given
// the chance they seize any unfortunate characters who cross their path,
// dragging them far into Deepearth as slaves.
inline bool dnaiAboleth()
    { return true; }

// water is obviously plentiful and the existing air quite breathable; a
// number of varieties of aquatic fungi and brown algae are commonly found in
// the water, and no minerals or other resources are known.
inline bool dnaiLakeResources()
    { return true; }

// the drain at the bottom of the lake is regulated by the kuo-toa so it
// always drains away water at the proper rate - the men-fish have placed
// boulders around the drain to block off part of the hole if the inflow
// slows, and other rocks can be pulled out of the way to accelerate the flow.
inline bool dnaiDrainRegulation()
    { return true; }

// the domed city of the kuo-toa is organized in a pattern of six major domes
// laid out in a hexagonal pattern.
inline int dnaiDomeCount()
    { return 6; }

// each of the six major domes of the kuo-toan city is about 150 feet in
// diameter.
inline int dnaiDomeDiaFt()
    { return 150; }

// each of the major domes is about 50 feet high.
inline int dnaiDomeHtFt()
    { return 50; }

// the top 20 feet of each major dome is filled with air, with an elaborate
// network of corridors and rooms nesting around elevator shafts - holes
// connecting the water-filled levels, up and down which the residents simply
// swim.
inline int dnaiDomeAirFt()
    { return 20; }

// the domed city of the kuo-toa lies next to the drain in one of the deepest
// parts of the lake - typical of kuo-toa communities, with its six hexagonal
// major domes and the elevator-shaft holes the residents simply swim up or
// down.
inline bool dnaiDomeCity()
    { return true; }

}   // namespace rules
