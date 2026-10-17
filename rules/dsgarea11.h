// =========================================================================================
// Adnd1 - rules/dsgarea11.h
// THE DSG DEEPEARTH AREAS 22-23, R544: printed pp. 92-93 (pdf 93-94) - the
// individual area key reaches the demihuman lands: Area 22 the Lands of the
// Deep Gnomes (the extensive region of long narrow north-south caverns
// stacked in three levels, averaging 20 by 10 feet, pinching to two or three
// feet once per mile; the streams never filling the passages and the
// gnome-built upper walks and spiral stairways; the excavated homes from tiny
// burrows to crawl-in residences; one clan per cave with its 60-by-8-foot
// council chamber; the central 200-by-10-foot meeting chamber ringed by the
// powerful clans; the ~5,000 svirfneblin with a third mobilizable; the
// protected rothe herds, 100 per clan and eight or 10 times that; the
// trickling fresh water and still pools; the Grand Canyon air circulation;
// the edible fungi; the iron-silver-copper-lead mines with five-mile shafts;
// the smelter and smithy with the coal fires venting to the lava sea; the
// traded and stockpiled surplus; and the vault - thousands of 500-sp silver
// bars behind the 550-Strength stone door opened weekly by winch teams and
// hidden by illusions), and Area 23 the Lower Grand Canyon (the lower portion
// of Area 7 descending another 1,200 feet; the duergar and deep gnome domains
// meeting at the canyon, their vast carved galleries of a thousand or more
// spectators facing each other across the 1,000-foot width; the 20-foot stone
// bridge; and the arena beneath - a three-dimensional web of stone arches,
// metal girders, rope ladders and nets where champion duels replace the wars
// of the past, nonmissile weapons only, the duergar-svirfneblin duels always
// fatal, the girder spacing hampering the small warriors while humans move
// easily).
// census 467 -> 468.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~11935-12079) with the pdf Acrobat-Capture layer as the second read
// (capture idx 212 = the printed p. 93 area-22 tail window and idx 214 head =
// the area 23 text); the compiled-tables appendix has no reprint of this
// prose. A CLEAN-READ ROUND: both machine reads agree on every load-bearing
// number - the three levels, the 20/10-ft averages, the once-per-mile 2-3-ft
// pinches, the 60/8-ft council chambers, the 200/10-ft meeting hall, the
// 5,000 population with a third mobilizable, the 100-rothe clans with 8-10x
// herds, the five-mile shafts, the 500-sp silver bars behind the 550-Strength
// door, the 1,200-ft descent, the thousand-spectator galleries across the
// 1,000-ft width, and the 20-ft bridge; no cross-read garbles this round -
// both reads are clean. SEAMS: the R518 water travel (the navigable-boat note
// lands in Area 24), the Monster Manual denizens (the svirfneblin, duergar,
// rothe and the Area 7 fauna by reference), the R521-R522 mining (the gnome
// and duergar mines), and the Area 7 Grand Canyon round itself. A ZERO-FLIP
// ROUND: the pp. 75-98 Deepearth child remains open until the setting lands
// in full (the R527/R533-R543 precedent - the gap report is NOT in the git
// add). Nothing auto-credits.
//
// A procedural-plus-prose round: no tables pin. The numbers pin as consts per
// the R508 convention - the cavern level count, the width and height
// averages, the pinch frequency and diameter bounds, the council and meeting
// chamber dimensions, the population, the rothe minimum and herd multiplier
// bounds, the mine shaft miles, the vault Strength and the silver bar value,
// the canyon descent and width and gallery capacity, and the bridge width.
// The geography, denizens, resources and unique-features prose pins as bools
// for both areas; no dice appear in this round. The water-travel/MM/mining
// seams are noted; the Deepearth child stays open; nothing auto-credits.
//
namespace rules {

// ---- the Area 22 Deep Gnomes section ----

// this extensive region of natural caverns comprises numerous long, narrow
// caverns all running north to south, side by side and also above and below
// each other.
inline bool dnamNorthSouthCaverns()
    { return true; }

// the deep gnomes' caverns are stacked in three distinct levels.
inline int dnamCavernLevels()
    { return 3; }

// the deep gnome caves average 20 feet wide.
inline int dnamCaveWideFt()
    { return 20; }

// the deep gnome caves average 10 feet high.
inline int dnamCaveHighFt()
    { return 10; }

// in many places the caves become much narrower than their average size.
inline bool dnamNarrowStretches()
    { return true; }

// at least once each mile travelers encounter a short narrow passage.
inline int dnamPinchPerMile()
    { return 1; }

// the once-per-mile passage is only two or three feet in diameter (the low
// bound).
inline int dnamPinchDiaLoFt()
    { return 2; }

// the once-per-mile passage is two or three feet in diameter (the high
// bound).
inline int dnamPinchDiaHiFt()
    { return 3; }

// streams flow through most of the caves but never completely fill the
// passages; where they come close to choking off tunnels, the svirfneblin
// have built upper passages so a gnome-sized character can walk anywhere
// without wet feet.
inline bool dnamStreamsDryFeet()
    { return true; }

// the vertical connections between caves are all deep-gnome-crafted small
// spiral stairways or ladders - tight squeezes for humans, but none too small
// for them to force through.
inline bool dnamGnomeStairways()
    { return true; }

// many small tunnels are excavated in the cave sides as svirfneblin homes,
// ranging from burrows too small for a human to large multi-family residences
// or council centers a human could crawl into and stand erect.
inline bool dnamExcavatedHomes()
    { return true; }

// each cave in the area is the home of a single clan of the deep gnomes, the
// most prestigious clans holding the largest caves.
inline bool dnamClanPerCave()
    { return true; }

// each clan maintains its own council chamber, an excavated chamber about 60
// feet in diameter.
inline int dnamCouncilDiaFt()
    { return 60; }

// the clan council chamber is eight feet high.
inline int dnamCouncilHighFt()
    { return 8; }

// the gnomes cooperate well and have established a clan meeting chamber in a
// central cave, surrounded by the residences of the most powerful clans.
inline bool dnamMeetingChamber()
    { return true; }

// the clan meeting chamber is a huge chamber 200 feet in diameter.
inline int dnamMeetingDiaFt()
    { return 200; }

// the meeting chamber ceiling is only 10 feet from the floor, with numerous
// columns supporting it.
inline int dnamMeetingCeilFt()
    { return 10; }

// the total population of svirfneblin numbers close to 5,000.
inline int dnamSvirfPop()
    { return 5000; }

// about 1/3 of the svirfneblin population is able to mobilize for military
// purposes, making them a force to be reckoned with in Deepearth.
inline bool dnamThirdMobilize()
    { return true; }

// many herds of rothe live in the same caverns as the svirfneblin; the gnomes
// protect them from the more savage predators and use their wooly hair and
// tasty meat, practicing selective breeding for a healthy livestock supply.
inline bool dnamRotheHerds()
    { return true; }

// each clan of svirfneblin keeps at least 100 rothe.
inline int dnamRothePerClan()
    { return 100; }

// larger rothe herds number eight or 10 times as many beasts as the clan
// minimum (the low bound).
inline int dnamHerdMultLo()
    { return 8; }

// larger rothe herds number eight or 10 times the clan minimum (the high
// bound).
inline int dnamHerdMultHi()
    { return 10; }

// fresh water trickles steadily into the caverns through many small wall and
// ceiling cracks; no single watercourse is a stream, but the trickles combine
// to the equivalent of a small stream per cave, gathering in a few large
// still pools.
inline bool dnamTrickleWater()
    { return true; }

// the caverns at the southern end of the domain gain air circulation through
// the Grand Canyon of Deepearth, enough to supply all the caverns amply.
inline bool dnamCanyonAir()
    { return true; }

// plant life is represented by the edible fungi that grow throughout the
// area.
inline bool dnamEdibleFungi()
    { return true; }

// the tunnels branching off the northeast end of the domain are ever-growing
// mines of iron, silver, copper and lead, extending deep into the earth and
// horizontally north and east, worked by the industrious gnomes for
// generations.
inline bool dnamGnomeMines()
    { return true; }

// many of the deep gnome mine shafts are over five miles long.
inline int dnamMineShaftMiles()
    { return 5; }

// a vast cavern connects the dwellings with the mining tunnels and holds a
// huge smelter and smithy; massive amounts of coal feed the roaring fires,
// and exhaust smoke vents through bedrock cracks into the lava sea caverns
// where it harmlessly disperses.
inline bool dnamSmelter()
    { return true; }

// svirfneblin blacksmiths, weaponsmiths and armorers toil endlessly creating
// high-quality weapons, armor and tools - many more than they need; some
// surplus is traded with other cultures and the rest stockpiled.
inline bool dnamSmithSurplus()
    { return true; }

// a huge stone door blocks off a large vault, sliding along a grooved floor
// track; the gnomes pull it aside about once a week with a work team of
// hundreds and a complicated system of winches and pulleys, and a number of
// illusions conceal the entrance.
inline bool dnamVaultDoor()
    { return true; }

// the vault door requires a combined Strength of 550 to open.
inline int dnamVaultStr()
    { return 550; }

// the vault contains thousands of bars of silver worth 500 sp apiece,
// alongside the excess products of the smiths.
inline int dnamSilverBarSp()
    { return 500; }

// ---- the Area 23 Lower Canyon section ----

// this is the lower portion of the Grand Canyon of Deepearth (Area 7), and
// the domains of the deep gnomes and the duergar both reach to the canyon
// itself.
inline bool dnamLowerCanyon()
    { return true; }

// the canyon walls descend another 1,200 feet from this point.
inline int dnamWallsDescendFt()
    { return 1200; }

// the canyon is bridged between Areas 22 and 24.
inline bool dnamBridgedDomains()
    { return true; }

// on each side of the canyon the demi-humans have carved vast galleries
// capable of holding a thousand or more spectators, facing each other across
// the canyon.
inline bool dnamCarvedGalleries()
    { return true; }

// each carved gallery holds a thousand or more spectators.
inline int dnamGalleryCap()
    { return 1000; }

// the canyon spans a 1,000-foot width at the bridge.
inline int dnamCanyonWideFt()
    { return 1000; }

// a sturdy stone bridge about 20 feet wide stretches between the two
// galleries.
inline int dnamBridgeWideFt()
    { return 20; }

// below the bridge, in full view of both galleries, is a three-dimensional
// web of stone arches, metal girders, rope ladders and nets - an arena of
// subterranean competition.
inline bool dnamArenaWeb()
    { return true; }

// denizens and resources are as explained under Area 7, noting that
// svirfneblin and duergar war parties constantly watch each other across the
// canyon.
inline bool dnamArea7Denizens()
    { return true; }

// the arena is a treacherous structure upon which most conflicts among the
// duergar and deep gnomes (and interracial fights) are resolved: the tragic
// costly wars of the past convinced the demi-humans to appoint a champion per
// faction and have them fight to the death rather than risk the devastation
// of war.
inline bool dnamChampionDuels()
    { return true; }

// the champions carry an assortment of nonmissile weapons onto the girders
// and fight to the death; the conflict may sometimes resolve sooner, but a
// duergar-svirfneblin duel always results in a fatality.
inline bool dnamNonmissileArms()
    { return true; }

// the three-dimensional arena allows a unique combat in which opponents
// maneuver for height, positions of security and openings for attack; the
// girders and beams are spaced far enough apart that the small warriors often
// have difficulty reaching each other, while humans and larger creatures move
// through more easily.
inline bool dnamArenaManeuver()
    { return true; }

}   // namespace rules
