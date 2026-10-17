// =========================================================================================
// Adnd1 - rules/dsgarea4.h
// THE DSG DEEPEARTH AREAS 8-9, R537: printed pp. 82-84 (pdf 83-85) - the
// individual area key crosses the tended garden and the great crossroads:
// Area 8 Fungus Forest (the maze-like circle of large chambers several
// hundred feet across and 50 or 60 feet high, joined by broad high tunnels
// that nothing a large ogre could not pass; the floors smoothed of all
// formations, everything else natural erosion; the dozen or so chambers
// carpeted with thick fungi - shriekers, violet fungus and a host of edibles
// - over deep soft loam with its faint smell of decay; the cross-bred
// mushrooms towering as much as 30 feet over the floor with narrow
// crushed-stone paths winding beneath; the isolated band of myconids tending
// the garden from the one fungus-free central cavern, cleaning blight and
// clearing away predators; the irrigation relay to Area 9 with its huge
// inverted water-bearing mushroom caps; the full circle of 20 fungus men
// under their very old king, driving off intruders rather than inquiring; the
// king's animator-spore zombies - several humans, a number of mobats, a pair
// of derro and a host of jermalaine - holding the line until all are
// defeated; the circulating but musty air, the imported water, the stone
// cistern, and the virtually unlimited food supply guarded by its myconids;
// and the continual-light permanent-levitation boulder, a foot across, kicked
// aloft to illuminate the whole room as it sinks over several hours), and
// Area 9 Caverns of Doom (the key crossroads of Deepearth; the western
// 1d3x10-ft cavern to the city dungeon, blocked with pits, chasms and cliffs,
// its dead-cave formations gone brittle; the five natural branch caverns to
// the other areas; the six truly immense central caverns, each linked to the
// other five, ceilings towering hundreds of feet and widths approaching 1,000
// feet, lengths of 2d6 miles, mule-passable routes around the chasms and
// rubble with connections at least 20 feet wide and 10 feet high; the name
// from the surface adventurers who assumed they had reached the utmost
// depths; the jermalaine bands roaming everywhere with their great northern
// community, the drow, duergar and pech pockets at odds, and the
// hobgoblin-goblin-troglodyte raiding parties from the city; the
// unintelligent menagerie - giant toads, stirges, piercers, large and huge
// spiders, jellies, puddings, molds, rust monsters, cockatrices, gargoyles,
// wraiths and wights; the edible fungi where water exists; the only decent
// water supply in this section of Deepearth, the ancient svirfneblin-built
// irrigation works with their sub-2-foot pipelines draining the Area 4
// streams to three separate caverns - two monopolized, the third shared by
// all comers including the myconids; the duergar and drow cave-pig herds, the
// gray-dwarf fungus gardens and the nomadic drow harvests; the pech
// prospectors exhausting each claim; the secret pech diamond mine screened by
// their wall of stone collective spell, the low-oxygen weeks sealed inside;
// the duergar fortified pool with its ceiling spout, its three blocked
// approach caves and the acid supply above; and the jermalaine honeycomb
// around the water pipe - the 18-to-24-inch lair passages, the high-rankers'
// private streams, and the exits 20 feet up the cavern wall with their
// pull-up rope ladders)
// census 460 -> 461.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~10465-10692) with the pdf Acrobat-Capture layer as the second read (idx
// 376-384 = the printed pp. 82-85 windows); the compiled-tables appendix has
// no reprint of this prose. A CLEAN-READ ROUND: both machine reads agree on
// every load-bearing number - the 50/60-ft chamber heights, the 30-ft caps,
// the myconid circle of 20, the one-foot boulder, the 1d3x10-ft city route,
// the five branch and six central caverns, the 1,000-ft widths, the 2d6-mile
// lengths, the 20/10-ft connections, the sub-2-ft pipelines, the three water
// caverns, the 18-to-24-inch passages, the 20-ft exit height and the three
// duergar approach caves; the only garbles are non-load-bearing (the capture
// 'ld3x 10' for 1d3x10 settled by the djvu, the djvu '9,' header comma, and
// spacing noise like 'Likeall theother' and 'stonecollective'). SEAMS: the
// Monster Manual denizens (the myconids and their animator spores, the
// jermalaine, drow, duergar, pech, svirfneblin, derro and the full monster
// menagerie), the PHB continual light, levitation and wall of stone spells,
// the R521-R522 mining and the pech stonework, and the R503 re-grain. A
// ZERO-FLIP ROUND: the pp. 75-98 Deepearth child remains open until the
// setting lands in full (the R527/R533-R536 precedent - the gap report is NOT
// in the git add). Nothing auto-credits.
//
// A procedural-plus-prose round: no tables pin. The numbers pin as consts per
// the R508 convention - the chamber heights, the cap and boulder sizes, the
// myconid circle, the city-route dice, the branch and central cavern counts,
// the great-cavern widths and lengths, the connection dimensions, the
// pipeline diameter, the water and approach-cave counts, and the jermalaine
// passage and exit sizes, with the 1d3x10 and 2d6 dice pinned as
// count-sides-and-multiplier const triples or pairs. The geography, denizens,
// resources and unique-features prose pins as bools for both areas. The
// MM/PHB/mining/R503 seams are noted; the Deepearth child stays open; nothing
// auto-credits.
//
namespace rules {

// ---- the Area 8 Fungus Forest section ----

// the area is connected to the canyon by one of the access tunnels and to
// Area 9 by a long natural cave; a number of large caverns join to form a
// maze-like circle of rooms, relatively devoid of formations apart from the
// occasional stalactite, the floors smoothed for walking - everything else
// the product of natural erosion, with no passage that would impede a large
// ogre or similar creature.
inline bool dnafMazeCircle()
    { return true; }

// the large, relatively open caverns of the maze-like circle include chambers
// several hundred feet in diameter and 50 or 60 feet high (the low bound).
inline int dnafChamberHtLowFt()
    { return 50; }

// many of the fungus-forest chambers are 50 or 60 feet high, with even the
// connecting tunnels relatively broad and high (the high bound).
inline int dnafChamberHtHighFt()
    { return 60; }

// each of the dozen or so chambers is literally carpeted with thick growths
// of fungi - every variety of mushroom including shriekers, violet fungus,
// and a host of edible fungi - with a deep layer of soft loam on each floor
// and a faint smell of decay in the air.
inline bool dnafFungiCarpet()
    { return true; }

// narrow paths lined with crushed stone wind among the tended fungi; movement
// off the paths is virtually impossible without crushing some of them.
inline bool dnafCrushedPaths()
    { return true; }

// many of the fungi have been carefully tended and cross-bred to grow to
// extreme heights; the caps of the tallest mushrooms tower as much as 30 feet
// over the floor.
inline int dnafCapMaxFt()
    { return 30; }

// the tenders of the vast underground plant garden are an isolated band of
// myconids living in the large central cavern - the only one not choked with
// growing fungi - who dutifully move among the other caverns, cleaning off
// any blight and clearing away creatures that threaten to eat the fungi.
inline bool dnafMyconidTenders()
    { return true; }

// the myconids' most important duty is irrigation: with no natural water
// supply in the area, they journey down the tunnel to Area 9 in a regular
// relay, returning with huge inverted mushroom caps filled with water, which
// is then allocated in precise amounts to the various caverns.
inline bool dnafIrrigationRelay()
    { return true; }

// this branch of myconid society includes all levels of fungus men,
// representing a full circle of 20 individuals.
inline int dnafMyconidCircle()
    { return 20; }

// the myconid king is a very old fungus who takes his responsibilities quite
// seriously; the myconids are not hostile or warlike but guard their domain
// jealously, tending to drive off intruders rather than inquire as to their
// purpose.
inline bool dnafMyconidKing()
    { return true; }

// the king has animated a number of zombies with his animator spores -
// several humans, a number of mobats, a pair of derro, and a host of
// jermalaine - serving as the initial guardians of the area; the myconids do
// not participate in combat unless all of the zombies have been defeated.
inline bool dnafSporeZombies()
    { return true; }

// the air circulates fairly well because of the Area 7 tunnel, but the
// dampness and mustiness of the loamy floor and spongy inhabitants makes it
// unpleasant to breathe; water must be imported, with the myconids
// maintaining a stone cistern for their own use and the rest keeping the soil
// moist.
inline bool dnafAirCistern()
    { return true; }

// the fungus forest could provide a virtually unlimited food supply to any
// hungry creature with access to it, but the guardian myconids make this
// access very difficult.
inline bool dnafUnlimitedFood()
    { return true; }

// a small boulder, about one foot in diameter, has been enchanted with
// continual light and permanent levitation, giving the stone a very slight
// negative buoyancy.
inline int dnafGlowBoulderDiaFt()
    { return 1; }

// one cavern contains fungus that thrives with limited light: when a myconid
// tends the room it kicks or hurls the enchanted glowing stone into the air,
// where over several hours it slowly sinks back to earth - shedding steady
// illumination over the entire room while airborne, and lighting only the
// area immediately around it when it falls.
inline bool dnafGlowStone()
    { return true; }

// ---- the Area 9 Caverns of Doom section ----

// the Caverns of Doom are a key section of Deepearth, connecting routes to
// and from many different places - the western city route blocked with pits,
// chasms and cliffs that make it very dangerous to travel.
inline bool dnafKeyHub()
    { return true; }

// the long, gradually sloping western cavern to the vast dungeon below the
// surface city is generally 1d3 x 10 feet wide, and equally high (the die
// count).
inline int dnafRouteDice()
    { return 1; }

// the dangerous city route is generally 1d3 x 10 feet wide (the die sides).
inline int dnafRouteSides()
    { return 3; }

// the city route is generally 1d3 x 10 feet wide and equally high (the
// multiplier).
inline int dnafRouteMultFt()
    { return 10; }

// like all the other areas adjacent to Area 9, the city-route cavern is a
// dead cave: the water that carved it has long since ceased to flow, and the
// cave formations have grown brittle and lost their shine.
inline bool dnafDeadCave()
    { return true; }

// five other natural caverns branch off the huge complex and lead to the
// other areas shown on the map - rough travel, but none blocked with the
// pitfalls that mar the route to the city.
inline int dnafBranchCaverns()
    { return 5; }

// six central caverns, each linked to the other five, make up the bulk of the
// area - a vast network of natural caves often linked by dungeons and
// excavated tunnels.
inline int dnafCentralCaverns()
    { return 6; }

// the central Caverns of Doom are truly immense, with ceilings towering
// hundreds of feet over the floor and widths approaching 1,000 feet.
inline int dnafCavernWidthFt()
    { return 1000; }

// the six central caverns range in length from 2d6 miles each (the die
// count).
inline int dnafCavernLenDice()
    { return 2; }

// the six central caverns range in length from 2d6 miles each (the die
// sides).
inline int dnafCavernLenSides()
    { return 6; }

// even the connecting routes between the caverns are at least 20 feet wide,
// so a carefully routed mule can make the passage despite the rough floors
// split by chasms, cliffs and rubble.
inline int dnafConnectWideFt()
    { return 20; }

// the connecting routes between the caverns are at least 10 feet high.
inline int dnafConnectHighFt()
    { return 10; }

// the name is derived from the tales of adventurers who penetrated this
// region and returned to the surface to tell of its terrors - adventurers who
// generally assumed they had descended into the utmost depths of the earth.
inline bool dnafDoomName()
    { return true; }

// the most proliferate denizens are the jermalaine, with small bands roaming
// the entire area and a large community in the northernmost cavern; other
// caverns contain pockets of drow, duergar and pech, none of them on friendly
// terms with each other, with occasional violent flareups and only the
// duergar attempting fortifications.
inline bool dnafRacePockets()
    { return true; }

// small bands of hobgoblins, goblins and troglodytes live in the dungeon
// beneath the city and in the cavern leading from the city to Area 9;
// encountered here, they are usually a small raiding party attempting to
// pillage the possessions of the permanent denizens.
inline bool dnafCityRaiders()
    { return true; }

// many unintelligent denizens dwell among the tunnels: giant toads, stirges,
// piercers, large and huge spiders, jellies, puddings, molds, rust monsters,
// cockatrices, gargoyles, wraiths and wights all roam the area in small
// numbers.
inline bool dnafMonsterMenagerie()
    { return true; }

// an assortment of fungi have sprouted in most parts of the caverns where
// water exists; shriekers or violet fungus are occasionally discovered, but
// most are of normal, and even edible, types.
inline bool dnafEdibleFungi()
    { return true; }

// the ancient irrigation system relies on several tubes cut through the rock
// to Area 4; the pipelines are less than two feet in diameter, indicating
// that the deep gnomes were the most probable builders.
inline int dnafPipelineDiaFt()
    { return 2; }

// water is drained from several of the Area 4 streams and diverted through
// the pipelines to three separate caverns in Area 9.
inline int dnafWaterCaverns()
    { return 3; }

// the Caverns of Doom are the only portion of this section of Deepearth with
// a decent water supply, thanks to a complicated irrigation system developed
// centuries earlier, presumably by the duergar or svirfneblin; the duergar
// and jermalaine monopolize two sources, while the third is centrally located
// and shared by all other denizens as well as the myconids of the fungus
// forest.
inline bool dnafIrrigationWorks()
    { return true; }

// the duergar and drow each maintain large herds of cave pigs; the gray
// dwarves grow a flourishing collection of edible fungi, while the nomadic
// drow harvest the fungi where they find it.
inline bool dnafCavePigs()
    { return true; }

// the pech have located a wide variety of precious metals and stones
// throughout the Caverns of Doom; the persistent miners generally exhaust
// each claim before moving on, their past mining activities obvious in many
// places.
inline bool dnafPechMining()
    { return true; }

// in one cavern the pech are engaged in one of their most ambitious
// excavations - a rich diamond mine the other denizens have not been able to
// locate; the pech furtively choose each work area and employ their wall of
// stone collective spell ability to screen it from all outside intrusion,
// their low oxygen requirements allowing them to remain sealed in a
// relatively small area for many weeks.
inline bool dnafPechDiamondMine()
    { return true; }

// the duergar fortified water area - a large pool fed through a spout in the
// ceiling - is accessible through three narrow caves, each blocked so
// thoroughly that creatures larger than the gray dwarves have difficulty
// squeezing through.
inline int dnafDuergarCaves()
    { return 3; }

// the duergar fortified area surrounds their water supply - a large pool fed
// through a spout in the ceiling - with access tunnels carved over each of
// the three blocked caves, holding small holes and a large supply of acid
// that can be cast onto intruders approaching through the caves below.
inline bool dnafDuergarFort()
    { return true; }

// the passages between the jermalaine lairs are only about 18 to 24 inches in
// diameter, so intrusion by larger creatures is difficult (the low bound).
inline int dnafJermaineDiaLowIn()
    { return 18; }

// the jermalaine lair passages are only about 18 to 24 inches in diameter
// (the high bound).
inline int dnafJermaineDiaHighIn()
    { return 24; }

// the outer exits of the jermalaine lairs have been dug into the wall of a
// large cavern about 20 feet off the floor, with rope ladders hanging from
// each entry tunnel to be quickly pulled up against attackers.
inline int dnafJermaineExitHeightFt()
    { return 20; }

// the jermalaine live in a honeycombed section of stone with dwellings carved
// from the area immediately surrounding the water pipe; many high-ranking
// jermalaine have small streams running through their lairs.
inline bool dnafJermaineHoneycomb()
    { return true; }

}   // namespace rules
