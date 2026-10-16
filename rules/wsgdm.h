// =========================================================================================
// Adnd1 - rules/wsgdm.h
// R492: the WSG DUNGEON MASTER SECTION slice, printed pp. 103-106 - the round
// CLOSING the section: the realism-vs-fantasy Earthlike assumption, the ten
// world-map steps from the 20-to-40-mile hex through the political
// guidelines, the fault-line and hot-spot placement, the clustering
// scale-down ladder and the winging-it improvisation rules - the world of
// weather appendix rides to R493.
// census 416 -> 417.
//
// THE SETTLE: the four DM-section pages two-way clean - the pdftotext layout
// reads and the tesseract tsv reconstructions agree on every number (the DMG
// page 47; the 20-to-40-mile hex scale; the 8.5-by-11 sheet - tesseract
// prints 87/2 for 8.5 - covering 1600 by 1250 miles, two million square
// miles; the 50-or-60 larger scale; the pp. 124-126 hex sheets; the
// 10,000-foot and 5,000-foot lines at 5,000-foot increments; the
// 20-to-40-mile hot spot diameter; the eight-hex cluster three wide at
// one-third - not an exact 3-to-1 for orientation reasons - with the 36-12-4
// ladder and the garbled 1V3 reading settled as 1-and-a-third miles, then
// about one half mile; the 20-to-30-foot small cliff) - printed pp. 103-106
// are pdf pages 104-107, the extraction branch b4daf47 carrying the
// thirteen-file set - md5 2f437a 1aa0262a999f410c533be81815 on the span read
// - after the pgm-not-png extraction lesson: pdftoppm -gray writes pgm files,
// and the failed glob on png yielded empty tesseract reads that the page-104
// retry closed.
//
// The ladder lesson: the 36-12-4-1-and-a-third cluster chain feeds the audit
// mirror, and every const is one mutant against it.
//
namespace rules {

// ---- The chapter opener ----

// the veteran Dungeon Master whose campaign world has outlived its
// usefulness: the players have explored practically every nook and cranny and
// his pride has waned - if the wonder and mystery is diminished for him, what
// must things be like for his players
inline bool wmdOldWorldFaded()
    { return true; }

// or the player taking the plunge to become a Dungeon Master for the first
// time, familiar with the rules and full of ideas aching for release
inline bool wmdFirstTimeDM()
    { return true; }

// either way he stands at a crossroads, about to start a new campaign world;
// it all begins with the first line drawn on a blank piece of paper that will
// become the world map, every mark eliminating some possibilities and opening
// up others
inline bool wmdCrossroads()
    { return true; }

// at some point the paper begins to look like a map and there is no going
// back without starting all over again; by then the map must stand as a firm
// foundation - a structure to add detail to that can support detail without
// limiting creativity
inline bool wmdNoGoingBack()
    { return true; }

// ---- Realism vs. fantasy ----

// this section will not tell you how to make a world where water flows
// uphill, a desert is bordered by a swamp, and a steaming tropical jungle is
// nestled between two arctic mountain ranges; if ideas run along those lines
// no help is needed - the game can be played in any kind of universe, even
// one where the natural laws of Earth do not apply
inline bool wmdNoUphillWater()
    { return true; }

// the assumption underlying practically every other paragraph in the book:
// the campaign world is one that could exist on Earth, or at least under
// Earthlike conditions - water flows downhill, you cannot go from a swamp to
// a desert without passing through some other kind of land, and sea-level
// tropical terrain is not also found at high elevation among snow-covered
// peaks
inline bool wmdEarthlikeAssumption()
    { return true; }

// the first advantage of an Earthlike world: both the Dungeon Master and the
// players are naturally familiar with the features of the planet; say
// mountain and they know what it means, unlike wooden mountains which raise
// slippery-question, splinter-question problems that strain the players
// suspension of disbelief until role-playing falls away in favor of an
// artificial contest
inline bool wmdFamiliarAdvantage()
    { return true; }

// the second point: homo sapiens is the dominant and predominant creature in
// the game universe, and the campaign world should be one in which player
// characters, human or demi-human, can survive and prosper and feel at home
// without biological or artificial adaptation - a methane-atmosphere world
// gives no character in his right mind a reason to adventure for fear of
// breaking his life-support apparatus
inline bool wmdHumanDominant()
    { return true; }

// the third point: the best campaign world is everpresent but usually
// inobtrusive - a backdrop for the activity between the characters and
// creatures that live in it, the location of a conflict but not the source of
// the conflict itself; keep the world in its proper place by making it
// ordinary so the characters concentrate on what they are doing instead of
// where they are doing it
inline bool wmdBackdropRule()
    { return true; }

// deviation from the norm is a good idea on a small scale: a boiling river or
// a forest that pulls itself underground at first frost remains intriguing
// when localized, but used everywhere it loses its distinctiveness and
// becomes an obstacle instead of an oddity
inline bool wmdDeviationSmallScale()
    { return true; }

// ---- Steps 1 and 2 ----

// the sunglasses principle: the obvious is often overlooked, and what is
// obvious to one person may not be apparent to another - read the
// step-by-step suggestions even if you know how to create a world map, in
// case you run across something that has not occurred to you
inline bool wmdObviousOverlooked()
    { return true; }

// step 1, settle on a scale: the Dungeon Masters Guide page 47 recommends the
// scale of a world map be from 20 to 40 miles per hexagon - the low bound
inline int wmdHexLoMph()
    { return 20; }

// the world map scale high bound: 40 miles per hexagon per the Dungeon
// Masters Guide recommendation
inline int wmdHexHiMph()
    { return 40; }

// the Dungeon Masters Guide page carrying the world map scale recommendation
inline int wmdDmgPage()
    { return 47; }

// it is not necessary to create an entire planet at one time; stick to
// something the size of a continent or part of a continent
inline bool wmdContinentSize()
    { return true; }

// at 40 miles per hex measured across the middle, a standard 8.5-by-11-inch
// piece of small-hexagon mapping paper covers roughly two million square
// miles - 1600 miles in the long dimension
inline int wmdPaperLongMi()
    { return 1600; }

// the short dimension of the hex-paper coverage at 40 miles per hex: 1250
// miles
inline int wmdPaperShortMi()
    { return 1250; }

// the rough area covered by the standard sheet of hex paper at 40 miles per
// hex: two million square miles
inline int wmdPaperSqMi()
    { return 2000000; }

// if the standard sheet is not large enough, fasten two or more sheets
// together and work in an even larger scale - 50 miles to the hex
inline int wmdBigHexLoMph()
    { return 50; }

// the upper larger-scale option: 60 miles to the hex; everything is scaled
// down later when a section needs detailing
inline int wmdBigHexHiMph()
    { return 60; }

// the world outline and features need not follow the hexagon boundaries - it
// is much better not to so restrict yourself; the hexes are only for
// regulating size and distance, and it is better to draw the map in rough
// form on blank paper and transfer it to hex paper later
inline bool wmdHexesRegulateOnly()
    { return true; }

// sheets of hex paper with different-sized hexagons are provided in the back
// of the book, pages 124-126 - the first page
inline int wmdHexSheetFirstPg()
    { return 124; }

// the last of the provided hex-paper pages; the book owner may photocopy the
// sheets for his personal use only
inline int wmdHexSheetLastPg()
    { return 126; }

// step 2, start at the bottom: pencil in an outline describing the coastline,
// planning for major islands, long peninsulas and other ultra-large-scale
// geographic features
inline bool wmdStartAtBottom()
    { return true; }

// unless there is a reason for a continent surrounded by water, extend the
// land mass off the edge of the map paper in at least one direction, keeping
// options open for connecting another land mass later or turning the
// continent into an island with a small extension of the original map
inline bool wmdLandOffEdge()
    { return true; }

// after step 2 the map shows all the places where the land meets the sea,
// which by definition also shows the location of zero elevation, or sea level
inline bool wmdSeaLevelLine()
    { return true; }

// ---- Steps 3 and 4 ----

// step 3, fake it to the top: place the mountain ranges and determine the
// tallest peaks - not too frequent or too high (characters should not scale a
// Mount Everest every few days), but not too low or they provide no good
// challenge and change of pace
inline bool wmdPeakBalance()
    { return true; }

// if any peaks are higher than 10,000 feet, draw shapes around those points
// indicating the line of 10,000-foot elevation
inline int wmdPeakLineFt()
    { return 10000; }

// after the 10,000-foot line, do the same for a line of 5,000-foot elevation
inline int wmdMidLineFt()
    { return 5000; }

// the resulting map is a rough topographical map showing the area lines of
// elevation at 5,000-foot increments - the rough shape of the world in all
// three dimensions is determined
inline int wmdIncrFt()
    { return 5000; }

// step 4, place it on the planet: decide where the world sits with respect to
// the poles and the equator, and note rough boundaries where the climatic
// zones change
inline bool wmdPlaceOnPlanet()
    { return true; }

// the world need not run the gamut from arctic to tropical climate, but it
// does not need to be hemisphere-sized to contain all five climatic regions
// either
inline bool wmdFiveRegionsEnough()
    { return true; }

// at this time determine the direction of the prevailing winds in each
// climatic area, using the weather-generation system in the appendix for
// general rules to aid the decisions
inline bool wmdPrevailingWinds()
    { return true; }

// ---- Steps 5 through 8 ----

// step 5, just add water: rivers begin at high elevation and run toward the
// ocean or some other place at or near zero elevation; a large river usually
// has several tributaries flowing into it
inline bool wmdRiversHighToSea()
    { return true; }

// extremely large river systems such as the Mississippi or the Amazon, with
// all the tributaries that feed them, are rarely found more than once or
// twice in a continent-sized area
inline bool wmdRareRiverSystems()
    { return true; }

// large inland bodies of water are somewhat less frequent in subarctic
// climates than in warmer areas, but a subarctic region may be laced with a
// dense intricate network of smaller rivers and lakes - Canada is the
// example, with Great Bear Lake and Great Slave Lake contradicting the
// frequency statement
inline bool wmdSubarcticWater()
    { return true; }

// do not be bashful about laying in rivers and lakes, but do not run a stream
// through every hex unless designing a world with no deserts
inline bool wmdDontStreamEveryHex()
    { return true; }

// step 5 is also the time to decide where the swamps go: in areas of low
// elevation, usually near or on the seacoast and usually in an area with a
// lot of rivers or lakes
inline bool wmdSwampPlacement()
    { return true; }

// step 6, what is for desert: on Earth most deserts are located in
// subtropical climate and the part of the temperate zone closer to the
// subtropical area - the southern half of the zone in the northern
// hemisphere, the northern half in the southern hemisphere
inline bool wmdDesertSubtropical()
    { return true; }

// the desert location is because of global wind patterns: prevailing winds
// blow generally east to west around the equator and usually in the opposite
// direction in the temperate regions; where they meet in the upper atmosphere
// over the area in between, the cool upper air descends, gets warmer, retains
// more moisture, and the water vapor stays suspended instead of falling as
// precipitation
inline bool wmdDesertWinds()
    { return true; }

// farther from the tropics deserts are often located on the downwind side of
// high mountain ranges: the air rises and cools against the slope, releasing
// precipitation on the wind-facing side, and by the time it crosses over all
// or most of its moisture is depleted
inline bool wmdDesertDownwind()
    { return true; }

// with those two facts in mind place the deserts, and be prepared to
// obliterate a river or at least change its course if the map shows water
// flowing through an area that would make a good desert - have an eraser
// handy
inline bool wmdDesertObliterateRiver()
    { return true; }

// step 7, may the forest be with you: mark off the forest areas, remembering
// they are more likely along or near large bodies of water
inline bool wmdForestPlacement()
    { return true; }

// do not go above the tree line where arctic climate begins, and do not put a
// forest right next to a desert unless creating a region of unearthly terrain
// there for a specific reason
inline bool wmdForestLimits()
    { return true; }

// step 8, none of the above: any terrain not designated seacoast, mountains,
// swamp, desert or forest must be either hills or plains
inline bool wmdHillsOrPlains()
    { return true; }

// if an area has no other distinguishing characteristics, the area adjacent
// to a mountainous region should be considered hills; spot some hilly regions
// in the middle of flat featureless areas just for variety, and as the
// next-to-last step anything else is plains
inline bool wmdAdjacentToMountainsHills()
    { return true; }

// ---- Steps 9 and 10 ----

// step 9, large-scale details: narrow the scope a bit - does the huge desert
// have an oasis or more than one, is there a pass through that awesome
// mountain range; mark these now so they do not have to be added when
// characters decide to look for them
inline bool wmdLargeScaleDetails()
    { return true; }

// large-scale additions and alterations: a thin strip of forest on either
// side of the big river slicing a vast plain is fine, and a river coursing
// through a desert is okay but must be bordered by a couple of strips of
// something other than desert - keep making finishing touches until satisfied
// with the lay of the land
inline bool wmdRiverThroughDesert()
    { return true; }

// step 10, points of interest: pinpoint the locations of special isolated
// features resembling the Grand Canyon, Death Valley or the Yellowstone area,
// and determine if the world has earthquakes or volcanoes and where the fault
// lines and hot spots go
inline bool wmdPointsOfInterest()
    { return true; }

// an earthquake can occur almost anywhere, but the most frequent and most
// severe quakes take place along major fault lines, often located where the
// land rises abruptly in elevation and especially near the seacoast - the San
// Andreas Fault in California is the example - or in the middle of a mountain
// range running along the long axis of the chain
inline bool wmdQuakeFaultLines()
    { return true; }

// individual volcanoes do not need to be placed on a very-large-scale map any
// more than every individual mountain peak does, but the hot spots must be
// known: the areas where volcanoes will be found, where magma lies close to
// the surface
inline bool wmdHotSpotDefinition()
    { return true; }

// each hot spot is an area of 20 to 40 miles in diameter - the low bound
inline int wmdHotSpotLoMph()
    { return 20; }

// the hot spot diameter high bound, usually located in the lower regions of a
// mountain range or along a major fault line that cuts through a mountain
// range
inline int wmdHotSpotHiMph()
    { return 40; }

// not every major fault line produces frequent earthquakes and not every hot
// spot contains active volcanoes, so do not be stingy about locating these
// special features - the characters have no way of knowing they exist until
// they become active, and a long-dormant volcano springing to life by design
// beats doing it on a whim
inline bool wmdNotEveryLineQuakes()
    { return true; }

// the more decisions made in the creation stage, the fewer times you will
// find yourself caught short later
inline bool wmdMoreDecisionsBetter()
    { return true; }

// ---- The semi-finished product ----

// the map is a one-of-a-kind creation but still not ready for adventures
// until it is brought alive: divide the terrain into countries, sketch the
// political boundaries and decide where the major population centers are - a
// much more complex and difficult process than that sentence indicates
inline bool wmdBringItAlive()
    { return true; }

// guideline 1: the largest population centers are usually located adjacent to
// large bodies of water, especially along the seacoast or on the shores of
// bodies of water with an outlet to the sea - the health of a city depends on
// commerce, and the most efficient way to move trade goods is by boat or ship
inline bool wmdCitiesByWater()
    { return true; }

// guideline 2: other large cities may be located in areas with an abundance
// of a useful natural resource - a city can spring up in the foothills
// several days travel from the nearest large river, as long as a road exists
// or can be built to a city on the river, with miners bringing their take to
// be assayed, refined and sold to a caravan that transports it to the
// manufacturing and shipping center
inline bool wmdResourceCities()
    { return true; }

// guideline 3: areas that are physically isolated tend to be politically
// independent, at least at the beginning of the world political history - an
// area ringed by or composed entirely of high mountains has a different
// government than the areas around it, Switzerland being the modern-day
// example
inline bool wmdIsolationIndependent()
    { return true; }

// the areas on either side of a vast desert will usually not belong to the
// same country, since a single central government cannot successfully
// exercise its power across a large expanse of impassable terrain
inline bool wmdDesertDivides()
    { return true; }

// guideline 4: in the absence of other factors, rivers often serve as
// political boundaries, to the advantage of the adjacent countries since
// there can be no doubt about where one country ends and another begins
inline bool wmdRiversBoundaries()
    { return true; }

// guideline 5: enclaves of humanoids and demi-humans usually occur in terrain
// suited to them - elves tend to be more numerous in forests, dwarves in
// mountains, and so forth
inline bool wmdEnclavesSuited()
    { return true; }

// flesh out the world in large scale by spotting the larger cities and the
// places where a creature type forms the predominant resident population,
// outline the countries perhaps leaving some political boundaries indefinite
// - that is how wars get started
inline bool wmdFleshOutWorld()
    { return true; }

// the worked example: Country A dislikes Country B for sending refined iron
// ore eastward to Country C across an almost-impassable mountain range; B
// sells the ore for weapons sent to the mountain passes near its border with
// A; Country D watches from the south playing a waiting game while building
// its military strength - three short paragraphs producing a simple situation
// with a wide range of consequences and several opportunities for adventurers
// to defuse or aggravate the tension
inline bool wmdCountryExample()
    { return true; }

// no matter which government the party works for, the characters are going to
// spend a lot of time in the wide open spaces and must know how to survive on
// the way to accomplishing what they are being paid to do
inline bool wmdAdventurersSurvive()
    { return true; }

// ---- Scaling down ----

// unless every character wears seven-league boots the world map is not useful
// in day-to-day adventuring: even at the smallest recommended scale there
// will be times when characters traveling overland do not cover the span of a
// single hex in a single day
inline bool wmdWorldMapNotDaily()
    { return true; }

// a good way to scale down is clustering: break a single large-scale hex into
// a cluster of eight smaller hexes and make a more detailed map of the area
// the large hex covers
inline bool wmdClusterMethod()
    { return true; }

// the number of smaller hexes in a cluster that one large-scale hex breaks
// into
inline int wmdClusterHexes()
    { return 8; }

// the cluster is three hexes wide, so the scale of each smaller hex is
// one-third of the world map scale - not an exact 3-to-1 ratio since the
// cluster hexes are always oriented differently from the larger hex, but
// close enough for the purpose
inline int wmdClusterWideHexes()
    { return 3; }

// the cluster scale divisor: one-third of the scale of the world map
inline int wmdClusterDiv()
    { return 3; }

// the worked example: each large-scale hex is 36 miles across
inline int wmdExampleHexMph()
    { return 36; }

// the 36-mile hex breaks into first-cluster hexes roughly 12 miles wide
inline int wmdFirstClusterMph()
    { return 12; }

// a 12-mile hex broken down gives cluster hexes 4 miles across
inline int wmdSecondClusterMph()
    { return 4; }

// the next step down is 1-and-a-third miles - numerator 4 over 3 (tesseract
// prints the garbled 1V3 miles; both reads agree on the thirds)
inline int wmdThirdClusterNum()
    { return 4; }

// the 1-and-a-third-mile scale denominator
inline int wmdThirdClusterDen()
    { return 3; }

// from 1-and-a-third miles to about one-half mile, and so on - the half-mile
// numerator
inline int wmdHalfMileNum()
    { return 1; }

// the half-mile denominator; just keep going as small as the scale needs
inline int wmdHalfMileDen()
    { return 2; }

// small-scale maps are not needed for every hex on the world map, at least
// not all at once: concentrate on the area the characters are in and heading
// toward, and be prepared with cluster maps of the territory the party is
// expected to travel through, drawn in as much detail as necessary
inline bool wmdClusterOnDemand()
    { return true; }

// if the characters head in an unexpected direction, either call a brief halt
// and generate some rough small-scale maps, or simply improvise without
// interrupting the flow of play
inline bool wmdUnexpectedDirection()
    { return true; }

// ---- Smaller scale, more detail ----

// the large-scale world map is a collection of generalities: the big green
// spot is a forest hundreds or thousands of square miles in area but not all
// forest; the large grassy plain is not just flat terrain - the map is a
// picture of the world as viewed from hundreds of miles overhead, where
// small-scale variations are not visible but are nevertheless there
inline bool wmdGeneralityMap()
    { return true; }

// as each hex breaks into a cluster keep in mind that terrain usually does
// not stay the same on a mile-by-mile basis: the monotony of a flat grassland
// is often broken by a grove of trees several hundred yards wide or a small
// forest a mile or two in diameter; a slight dip in a forest elevation makes
// swampy ground among the trees
inline bool wmdTerrainVaries()
    { return true; }

// a small cliff, perhaps only twenty or thirty feet high, can show up almost
// anywhere on otherwise flat terrain - the low bound
inline int wmdCliffLoFt()
    { return 20; }

// the small-cliff high bound
inline int wmdCliffHiFt()
    { return 30; }

// with each step to a smaller scale the detail of the hex maps and the
// variety in terrain and special features should increase: if a river cuts
// through the hex being scaled down, draw in streams coming off the main
// branch; if the large-scale hex takes in part of a lake, sketch in swampy
// ground along the lakeshore at the next smaller scale - a swamp that does
// not show up on the large-scale map but is there nevertheless
inline bool wmdMoreDetailEachStep()
    { return true; }

// ---- Winging it ----

// a Dungeon Master must be able to think on his feet: no matter how much
// planning goes in, the players will occasionally have their characters do
// something or go somewhere unanticipated - more often than not the problem
// is an opportunity in disguise, the opportunity to create and decide on the
// spot during the game
inline bool wmdThinkOnFeet()
    { return true; }

// when characters move into an area not yet mapped in detail, improvise and
// invent within reason any special features that make the segment more
// interesting or give the players things to think about - more than just
// there is forest around you as far as you can see
inline bool wmdImproviseWithinReason()
    { return true; }

// the worked improvisation: a lightly wooded area where most trees are the
// same height except one big oak to the east towering over the others, a
// clearing to the north where sunlight reaches the ground, the land sloping
// gradually upward to the west with few trees at the peak
inline bool wmdOakExample()
    { return true; }

// improvising this way impresses the players with the Dungeon Master
// organization and attention to detail, and more importantly creates
// possibilities for excitement and intrigue: climb the oak and maybe see
// something important in the distance, move to the clearing and maybe find a
// path through the rest of the forest, climb the slope and maybe discover a
// sharp dropoff with a small pool at the bottom
inline bool wmdImprovisationPays()
    { return true; }

// the only rule when improvising: you cannot un-create something later - keep
// track of what you tell the players, either in brief notes or preferably by
// sketching the features just described on a handy sheet of hex paper
inline bool wmdCantUncreate()
    { return true; }

// if the characters visit a spot more than once they will expect to see the
// same details described when they first arrived; between sessions take a few
// minutes to update the collection of small-scale maps incorporating the
// features devised during the game, so you will not be caught short if the
// characters backtrack or stumble upon the same location later
inline bool wmdRepeatVisits()
    { return true; }

// the closing: all the rules still provide nothing more than a framework upon
// which the world and adventures are built - the pieces to a puzzle with an
// infinite number of different solutions, and it is up to the Dungeon Master
// to put those pieces together
inline bool wmdFrameworkClosing()
    { return true; }

}   // namespace rules
