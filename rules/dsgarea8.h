// =========================================================================================
// Adnd1 - rules/dsgarea8.h
// THE DSG DEEPEARTH AREAS 16-17, R541: printed pp. 88-89 (pdf 89-90) - the
// individual area key descends the stairway and crosses the great lower
// water: Area 16 Mid-Level Caverns (the carefully engineered spiral stairway
// from the Area 14 tunnel - a full 1,000 feet down, each stair 10 feet wide,
// one-foot deep, dropping eight inches around the hollow 10-foot shaft with
// no guardrail; the living caves with their seeping streams and common
// formations; the dominant central cave with the most spectacular drapery
// formations in all Deepearth, ringed by more than a dozen smaller caves; the
// steep western descent - a 20-foot cavern half that in height, broken by
// 1d6x10-ft cliffs with ledged, climbable faces, pinching to three feet in
// two places; the clear deep pools - the largest 50 feet across, commonly 20
// to 30 feet deep; the wilderness status despite the stairway, with pech,
// jermalaine, derro and drow only passing through; the monster caves - the
// greater basilisk and mimics of the center, the bowlers, trappers, xorn,
// piercers, rock reptiles, scum creepers and mud men of the flanks; the fresh
// water, the stuffy-but-breathable air, the poolside fungi; the continuing
// Area 14 copper and iron veins showing green and red through the draperies;
// and the mud men's mild-enchanted stream - a potion of healing if drunk from
// its niche, its magic lost to any container, radiating alongside the mud
// pool it feeds), and Area 17 the Lower Lake of Deepearth (the
// twelve-by-thirteen-mile open cavern, 600 feet high with the bottom 500 feet
// water-filled; the constant ceiling-spout column from the Upper Lake drain
// and its ring of turbulence over the otherwise placid waters; the
// inaccessible shoreline cliffs and the Area 16 tunnel mouth 50 feet above
// the surface; the broad northern river - 100 feet wide, 1d10+10 feet deep,
// its ceiling 20 to 50 feet over the water; the silt-coated smooth rock
// floor; the half-dozen underwater caves, their mouths at least 100 feet
// down; the ongoing aboleth-kuo-toa war of outposts and savage
// surface-and-depth battles; the kuo-toan southern domed city and its
// well-worn path between the lakes; the 300 aboleth of the northern floating
// city, its river-mouth guards; the fresh-water kraken of the largest side
// cavern, its 40-foot entrance tunnel, its 50 mixed-race slaves and their
// temporary truce, the tailing-stone pile betraying the excavation; the
// lake-floor gold dust under the spout - more than 100,000 gp at a 500-foot,
// kraken-and-aboleth-guarded depth; the drain plunge itself - 2d6 rounds
// submerged, the 100-foot fall, 6d6 to non-natives halved by a save vs.
// breath weapon, 3d6 to water-natives negated by their saves; the aboleth
// city - the 1,000-foot mucous disk with its six slim towers and drain-holed
// wall that strands victims high and dry; the sphere buildings -
// 20-to-30-foot lairs with one entrance, 100-foot nurseries, prisons and
// Three-Clan halls with six, every entrance a three-foot hole, interiors half
// water and half air with perch ledges, each slave race held apart; and the
// 40-foot buoyancy disk at the foundation, air-filled and rising on command)
// census 464 -> 465.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~11260-11493) with the pdf Acrobat-Capture layer as the second read (idx
// 400-412 = the printed pp. 88-90 windows); the compiled-tables appendix has
// no reprint of this prose. A CLEAN-READ ROUND: both machine reads agree on
// every load-bearing number - the 1,000-ft stairway with its 10-ft/1-ft/8-in
// stairs and 10-ft shaft, the 20-ft west cavern with 1d6x10-ft cliffs and two
// 3-ft pinches, the 50-ft and 20/30-ft pools, the 12x13-mile cavern, the
// 600-ft height and 500-ft water, the 50-ft tunnel mouth, the 100-ft river
// with 1d10+10 depth and 20/50-ft ceiling, the six 100-ft-down cave mouths,
// the 300 aboleth, the 100,000-gp gold, the 2d6/100-ft/6d6/3d6 drain plunge,
// the kraken's 40-ft tunnel and 50 slaves, and the city's 1,000-ft disk, six
// towers, 20/30/100-ft spheres with 3-ft holes and 40-ft buoyancy disk; the
// only garbles settled cross-read (the capture '1dlO + 10' for the djvu's
// 1d10 + 10). SEAMS: the R518 water travel (the river and the drain plunge),
// the Monster Manual denizens (the basilisk, mimics, bowlers, trappers, xorn,
// mud men, kuo-toa, aboleth, kraken and the rest), the PHB potion of healing
// and detect magic (the mud-pool stream), the R521-R522 mining (the ore veins
// and the gold dust), and the R503 re-grain. A ZERO-FLIP ROUND: the pp. 75-98
// Deepearth child remains open until the setting lands in full (the
// R527/R533-R540 precedent - the gap report is NOT in the git add). Nothing
// auto-credits.
//
// A procedural-plus-prose round: no tables pin. The numbers pin as consts per
// the R508 convention - the stairway feet, the west-cavern cliffs and
// pinches, the pool sizes, the lake's dimensions and depth, the river's
// width, dice and ceiling, the underwater cave count and depth, the aboleth
// count, the gold-dust value, the drain-plunge dice and damages, the kraken's
// tunnel and slaves, and the aboleth city's disk, towers, spheres and
// buoyancy thickness, with the 1d6x10, 1d10+10, 2d6, 6d6 and 3d6 dice pinned
// as count-sides(-multiplier/base) const triples or pairs. The geography,
// denizens, resources and unique-features prose pins as bools for both areas.
// The water-travel/MM/PHB/mining/R503 seams are noted; the Deepearth child
// stays open; nothing auto-credits.
//
namespace rules {

// ---- the Area 16 Mid-Level section ----

// the tunnel from Area 14 ends in a long, carefully engineered spiral
// stairway that descends a full 1,000 feet.
inline int dnajStairDescendFt()
    { return 1000; }

// each stair of the spiral stairway is 10 feet wide.
inline int dnajStairWideFt()
    { return 10; }

// each stair is one-foot deep (the tread).
inline int dnajStairDeepFt()
    { return 1; }

// each stair drops eight inches.
inline int dnajStairDropIn()
    { return 8; }

// a hollow, 10-foot-diameter shaft plummets straight down the middle of the
// stairway - there is no guardrail.
inline int dnajShaftDiaFt()
    { return 10; }

// the mid-level caverns are typical examples of living caves - several
// streams flow through them, fed by water seeping from narrow cracks in the
// walls and ceilings, and cave formations are common.
inline bool dnajLivingCaves()
    { return true; }

// one large central cave dominates the area, surrounded by more than a dozen
// smaller caves; the central cave contains some of the most spectacular
// drapery formations in all of Deepearth.
inline bool dnajDraperies()
    { return true; }

// the steeply descending western natural cavern averages about 20 feet in
// width and half that in height, with a small stream splashing through its
// length.
inline int dnajWestCavernWidFt()
    { return 20; }

// the western cavern is broken at many places by cliffs of 1d6 x 10 feet in
// height, their rough cracked faces ledged so climbing down is not difficult
// (the die count).
inline int dnajCliffDice()
    { return 1; }

// the western cavern's cliffs are 1d6 x 10 feet high (the die sides).
inline int dnajCliffSides()
    { return 6; }

// the western cavern's cliffs are 1d6 x 10 feet high (the multiplier).
inline int dnajCliffMultFt()
    { return 10; }

// in two places the western cavern narrows to about three feet in diameter.
inline int dnajPinchCount()
    { return 2; }

// the two western pinches narrow the cavern to about three feet in diameter.
inline int dnajPinchDiaFt()
    { return 3; }

// several clear, deep pools fill the caves; the largest of these is only 50
// feet in diameter.
inline int dnajPoolMaxDiaFt()
    { return 50; }

// the pools are commonly 20 to 30 feet deep (the low bound).
inline int dnajPoolDeepLowFt()
    { return 20; }

// the pools are commonly 20 to 30 feet deep (the high bound).
inline int dnajPoolDeepHighFt()
    { return 30; }

// despite the carefully constructed stairway providing access, the area
// should be classified as a wilderness - no organized groups of intelligent
// creatures live here, though pech, jermalaine, derro and drow may all be
// encountered passing through.
inline bool dnajWildernessPass()
    { return true; }

// a number of monsters have taken up residence and regard these caverns as
// their own territory: the large central cave contains a greater basilisk and
// a number of mimics, while the surrounding smaller caves hold bowlers,
// trappers, a xorn, piercers, rock reptiles, scum creepers and, in one
// location, mud men.
inline bool dnajMonsterCaves()
    { return true; }

// the water here is fresh and clean, the air circulated enough to remain
// breathable though rather stuffy; many varieties of fungi thrive here,
// especially near the pools.
inline bool dnajMidResources()
    { return true; }

// the same veins of copper and iron ore excavated by the pech in Area 14
// provide access to those mineral ores here - visible in a number of places
// as streaks of greenish rock for copper or reddish rock for iron, their
// colors contributing to the elaborate drapery formations of the central
// chamber.
inline bool dnajOreVeins()
    { return true; }

// a small stream trickles from a crack in the side of the mud men's cavern,
// emptying into a wide pool of mud that completely fills the cave's bottom,
// so the only access to the stream is wading through the mud pool's fringes;
// the stream's water is of mild enchantment, radiating magic - as does the
// mud pool - and acts as a potion of healing if drunk from its niche in the
// wall, losing all magical properties if any container is used to carry it,
// even from the streambed to a character's mouth.
inline bool dnajMudPool()
    { return true; }

// ---- the Area 17 Lower Lake section ----

// the Lower Lake occupies a large, open cavern about twelve miles long.
inline int dnajLakeLongMiles()
    { return 12; }

// the lake's cavern is thirteen miles wide at its broadest point.
inline int dnajLakeWideMiles()
    { return 13; }

// the chamber is about 600 feet high.
inline int dnajChamberHtFt()
    { return 600; }

// the bottom 500 feet of the chamber are filled with water.
inline int dnajWaterDepthFt()
    { return 500; }

// near the center of the ceiling a constant column of water spills from the
// drain in the Upper Lake; the water around this column is quite turbulent,
// but the rest of the lake is rather placid - the lake's shoreline is
// inaccessible, rocky cliffs dropping far below the water line on all sides,
// though the cracked rough walls are not difficult to climb.
inline bool dnajSpoutTurbulence()
    { return true; }

// the cavern leading here from Area 16 ends in a tunnel mouth 50 feet above
// the surface of the lake.
inline int dnajTunnelMouthFt()
    { return 50; }

// the broad, placid northern river flowing from the lake maintains a fairly
// constant width of about 100 feet.
inline int dnajRiverWideFt()
    { return 100; }

// the northern river's depth is 1d10 + 10 feet (the die count).
inline int dnajRiverDepthDice()
    { return 1; }

// the northern river's depth is 1d10 + 10 feet (the die sides).
inline int dnajRiverDepthSides()
    { return 10; }

// the northern river's depth is 1d10 + 10 feet (the base).
inline int dnajRiverDepthBaseFt()
    { return 10; }

// the river cavern's ceiling is always at least 20 feet above the water
// level, sometimes soaring as much as 50 feet from the surface (the low
// bound).
inline int dnajRiverCeilLowFt()
    { return 20; }

// the river cavern's ceiling sometimes soars as much as 50 feet from the
// water's surface (the high bound).
inline int dnajRiverCeilHighFt()
    { return 50; }

// a half-dozen underwater caves penetrate the cliffs bordering the lake,
// their mouths all at least 100 feet below the water's surface.
inline int dnajUnderCaveCount()
    { return 6; }

// the mouths of the underwater caves are all at least 100 feet below the
// water's surface.
inline int dnajUnderCaveMouthFt()
    { return 100; }

// the Lower Lake is the scene of an ongoing struggle between the aboleth and
// the kuo-toa - each race maintains outposts, and savage battles often rage
// both on the surface and in the depths.
inline bool dnajLakeWar()
    { return true; }

// the kuo-toa have built a domed city near the southern end of the lake, very
// similar to their Upper Lake community; the men-fish often travel between
// the two lakes on a well-worn path up to the tunnel mouth near their lair,
// though occasionally one follows the water down the drain despite the
// inherent risks of the plunge.
inline bool dnajKuoSouthCity()
    { return true; }

// about 300 aboleth occupy the lake dwellings, though nearly half of them may
// be swimming in other parts of the lake at any given time, with a small
// group always on guard at the mouth of the river.
inline int dnajAbolethCount()
    { return 300; }

// the aboleth have erected their own floating city at the lake's northern end
// and attempt to exert strict control over creatures using the river to exit
// or enter the lake.
inline bool dnajAbolethNorthCity()
    { return true; }

// the only other lake denizen is given a wide berth by both the aboleth and
// the kuo-toa: a massive kraken that has somehow adapted itself to live in
// fresh water, dwelling in the largest of the side caverns, its excavations
// marked by a huge pile of tailing stone at the lake bottom beneath the
// cavern.
inline bool dnajKrakenLair()
    { return true; }

// a constant supply of fresh air finds its way into the cavern through
// several entrances, and the spout of water from the ceiling throws out
// enough turbulence to keep it circulating; the lake also hosts a number of
// waterborne fungi and numerous fish upon which other creatures survive.
inline bool dnajLakeResources()
    { return true; }

// a vast amount of gold in the form of tiny flakes has settled on the lake
// floor directly under the waterspout, its total value exceeding 100,000 gp -
// but the 500-foot depth, the kraken, aboleth, and kuo-toa make mining here a
// very risky operation.
inline int dnajGoldDustGp()
    { return 100000; }

// any character following the water through the Upper Lake's drain remains
// submerged for 2d6 rounds (the die count).
inline int dnajDrainRoundsDice()
    { return 2; }

// the drain plunge submerges a follower for 2d6 rounds (the die sides).
inline int dnajDrainRoundsSides()
    { return 6; }

// the water bursts through the hole in the Lower Lake's ceiling and plummets
// 100 feet straight down.
inline int dnajFallFt()
    { return 100; }

// characters and creatures not native to water sustain 6d6 of damage from
// this fall, reduced to half damage if a save vs. breath weapon is successful
// (the die count).
inline int dnajFallDmgDice()
    { return 6; }

// the drain fall deals 6d6 damage to non-native creatures (the die sides).
inline int dnajFallDmgSides()
    { return 6; }

// creatures native to water, such as the kuo-toa and aboleth, sustain 3d6 of
// damage - and none if their saving throws are successful (the die count).
inline int dnajFallNativeDmgDice()
    { return 3; }

// native creatures sustain 3d6 damage from the fall (the die sides).
inline int dnajFallNativeDmgSides()
    { return 6; }

// the entrance tunnel of the kraken's cavern - the largest of the caves
// branching off the lake - is 40 feet in diameter, leading into a vast
// complex of caverns, some completely water-filled, others partially filled
// with air.
inline int dnajKrakenTunnelDiaFt()
    { return 40; }

// the kraken has no less than 50 slaves toiling to expand the caverns for the
// greater glory of their tyrannical master - an odd mix of human adventurers,
// drow, duergar, svirfneblin, and even a couple of kuo-toa, holding a
// temporary truce against the day they might strike out for freedom.
inline int dnajKrakenSlaves()
    { return 50; }

// the aboleth city is not attached to any surface: designed for neutral
// buoyancy, it floats at whatever depth the aboleth desire, a broad disk
// about 1,000 feet in diameter encased in cloudy mucous like the aboleth
// themselves.
inline int dnajCityDiaFt()
    { return 1000; }

// six slim towers rise around the outside boundaries of the aboleth city,
// often the only portions extending above the surface of the water, connected
// by a fairly high wall whose base is pierced with drain holes - the aboleth
// come up under an enemy, the trapped water drains away, and the victims are
// left high and dry.
inline int dnajCityTowers()
    { return 6; }

// the city's buildings are almost perfect spheres resting on narrow bases,
// the bottom 10% submerged; the smaller ones (20-30 feet in diameter) are
// individual lairs (the low bound).
inline int dnajSphereSmallLowFt()
    { return 20; }

// the smaller sphere buildings run 20-30 feet in diameter with one entrance
// each (the high bound).
inline int dnajSphereSmallHighFt()
    { return 30; }

// the largest sphere buildings are about 100 feet in diameter and have six
// entrances each.
inline int dnajSphereLargeFt()
    { return 100; }

// each sphere entrance is simply a three-foot-diameter hole near the base.
inline int dnajSphereEntranceDiaFt()
    { return 3; }

// the aboleth city's buildings are all single-room spheres filled half with
// water and half with air, frequently with perch-like ledges halfway up their
// interior walls; the larger ones serve as nurseries for the aboleth young or
// prisons for their many human, drow, pech, derro, and duergar slaves, each
// race held in a different structure.
inline bool dnajSphereInteriors()
    { return true; }

// the largest sphere buildings are the halls of government for the Three
// Clans, each clan with its own building - many ledges up and down the
// interior walls where the clan members perch when their sessions convene.
inline bool dnajClanHalls()
    { return true; }

// the buoyancy-controlling mechanism is located in the city's foundation
// disk, about 40 feet thick - seemingly solid but riddled with a maze of
// corridors and machinery rooms behind sturdy doors; most of this area is
// air-filled, providing the city's positive buoyancy when the controller
// wishes it to rise.
inline int dnajBuoyDiskFt()
    { return 40; }

}   // namespace rules
