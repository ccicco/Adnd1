// =========================================================================================
// Adnd1 - rules/dsgarea3.h
// THE DSG DEEPEARTH AREAS 6-7, R536: printed pp. 81-82 (pdf 82-83) - the
// individual area key reaches the old dead heart of Deepearth and its great
// chasm: Area 6 Caverns of the Ancients (the small cave series showing
// considerable excavation and decoration - the single 30-ft-wide,
// 10-ft-ceiling entry tunnel leading to the huge domed chamber nearly 1/2
// mile across, its massive stone columns, and the elaborate bestial temple at
// the exact center; the concentric rings of two- and three-story stone
// buildings with their wide smooth avenues and the crude stone barracks of
// the cavern wall; the tall palace with its elegantly thin columns and its
// huge shut brass doors - the only closed doorways in the city - and the
// hundreds of rooms branching from the facade towering 100 feet high and 300
// feet to either side; the five additional tunnels at 60-degree intervals,
// once the city's farmland and now uniformly dusty and empty; the duergar
// builders driven deeper by the water-table shift that dried their wells,
// leaving not a single living creature or plant; the palace honor guard of
// hundreds of zombies, skeletons and mummified leaders that attacks when the
// doors open and pursues only to the Area 6/7 tunnel juncture; the
// centuries-stale dry air that stops the exerting after 2d6 rounds with
// 1d6-round recoveries; the stripped stone furniture, the fragile crumbling
// wood, the fungus farms and cave-pig corrals gone to dust; and the secret
// palace-hall trapdoor to the smithy - the extinguished furnaces, the massive
// black 25,000-gp forge-of-power anvil with its +1 enchantments, and the
// +2/+3 weapons possible with a hammer of substance), and Area 7 Grand Canyon
// of Deepearth (the yawning chasm over ten miles long and fully a mile wide,
// its naturally arched 200-ft ceiling at the Area 6 entrance; the walls
// meeting in the boulder-and-rubble gorge over a mile below; the
// water-erosion origin and the great river that died with the duergar wells;
// the old, generally stable, crack-and-ledge-riddled rock with no bridges at
// this height; the hidden cavern series 3,000 feet down and two miles south
// of the upper tunnels; the limestone cave mouths as deep as 300 feet at
// their 500-ft intervals; the 1-to-3-ft vertical shafts to the surface city's
// sewers, useless to all but bats; the great bat numbers with their several
// hundred mobats attacking in 2d6 groups; the cave fishers, the pair of giant
// slugs scouring the bottom, the giant centipedes and the wall-crawling
// carrion crawlers; the two dozen cloakers of the highest caves, 50% drawn to
// mobat combats to finish the wounded; the stagnant unfed pools with their
// 50% disease chance; and the sparse wall-niche lichens and fungi)
// census 459 -> 460.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~10303-10463) with the pdf Acrobat-Capture layer as the second read (idx
// 372-376 = the printed pp. 81-83 windows); the compiled-tables appendix has
// no reprint of this prose. A CLEAN-READ ROUND: both machine reads agree on
// every load-bearing number - the 30-ft tunnel with its 10-ft ceiling, the
// half-mile dome, the 100/300-ft facade, the 60-degree intervals and five
// tunnels, the 2d6/1d6 air rounds, the 25,000-gp anvil with its +1 and +2/+3
// bonuses, the ten-mile canyon, the 200-ft ceiling, the mile-deep gorge, the
// 3,000-ft and two-mile hidden caverns, the 300-ft cave mouths at 500-ft
// intervals, the 1-to-3-ft shafts, the 2d6 mobat groups, the 50% cloaker
// draw, the two dozen cloakers and the 50% pool-disease chance; the only
// garbles are non-load-bearing (the djvu '5096' for the 50% chance and the
// Capture 'ld6' for 1d6, each settled by the other read, plus the 'balancc'
// and 'ofpowerof' spacing noise). SEAMS: the Monster Manual denizens (the
// duergar, the undead host, the mobats, cave fishers, giant slugs,
// centipedes, carrion crawlers and cloakers), the PHB cause disease spell and
// the hammer of substance, the duergar forge-of-power magic, and the R503
// re-grain. A ZERO-FLIP ROUND: the pp. 75-98 Deepearth child remains open
// until the setting lands in full (the R527/R533/R534/R535 precedent - the
// gap report is NOT in the git add). Nothing auto-credits.
//
// A procedural-plus-prose round: no tables pin. The numbers pin as consts per
// the R508 convention - the entry-tunnel width and ceiling, the dome, facade
// and tunnel intervals, the air-stress dice, the anvil's weight and
// enchantment bonuses, the canyon's dimensions and depths, the cave-mouth
// sizes and intervals, the shaft diameters, the mobat dice, the cloaker odds
// and the pool-disease chance, with the 2d6/1d6/2d6 dice pinned as
// count-and-sides const pairs. The geography, denizens, resources and
// unique-features prose pins as bools for both areas. The MM/PHB/forge/R503
// seams are noted; the Deepearth child stays open; nothing auto-credits.
//
namespace rules {

// ---- the Area 6 Ancients section ----

// the single entry tunnel of the ancient city was smoothed and widened to a
// uniform width of 30 feet.
inline int dnaeEntryTunnelWidthFt()
    { return 30; }

// the entry tunnel has a uniform ceiling of 10 feet along its length.
inline int dnaeEntryTunnelCeilFt()
    { return 10; }

// the entry corridor leads to a huge, domed chamber nearly 1/2 mile in
// diameter; massive stone columns support the ceiling and an elaborate temple
// carved with bestial shapes stands at the exact center.
inline int dnaeDomeDiaHalfMile()
    { return 1; }

// this relatively small series of caves shows considerable evidence of
// excavation and decoration: the concentric rings of two- and three-story
// stone buildings around the bestial temple, separated by wide smooth
// avenues, with a ring of crude stone barracks in the cavern wall providing
// the only simple quarters in the ancient city.
inline bool dnaeExcavatedCity()
    { return true; }

// the tall palace stands surrounded by elegantly thin columns, and its huge
// brass doors stand shut - the only closed doorways in the city.
inline bool dnaeBrassDoors()
    { return true; }

// at the end opposite the entrance tunnel stands the tall palace; its facade
// towers fully 100 feet high.
inline int dnaePalaceFacadeHtFt()
    { return 100; }

// the palace facade stretches for 300 feet to either side of the main
// entrance, with hundreds of rooms branching out.
inline int dnaePalaceFacadeSideFt()
    { return 300; }

// at 60-degree intervals about the circular walls of the cavern, five
// additional tunnels branch out to smaller caverns.
inline int dnaeTunnelIntervalDeg()
    { return 60; }

// five additional tunnels branch out from the circular cavern walls to the
// smaller side caverns - now uniformly dusty and empty, though they once
// served as farmland for the city's residents.
inline int dnaeSideTunnelCount()
    { return 5; }

// the original builders of the city were the duergar; shifts in the water
// table centuries ago dried up their wells and forced the race to migrate
// deeper underground, and now not a single creature or plant lives in the
// area.
inline bool dnaeDuergarExodus()
    { return true; }

// an honor guard of undead stands at attention around the massive hall of the
// palace - hundreds of zombies, skeletons, and mummified leaders arrayed to
// lead the host to battle; if the palace doors are opened the orders to
// attack are given, and the undead pursue a foe only to the juncture of the
// Area 6 and Area 7 tunnels.
inline bool dnaeUndeadHonorGuard()
    { return true; }

// the area is completely dry - not so much as a cup of water - and the stale
// air smells faintly of decay and is of very poor quality.
inline bool dnaeDeadAirDry()
    { return true; }

// no fresh air has entered this region for centuries; characters exerting
// themselves have to stop, gasping, after 2d6 rounds (the die count).
inline int dnaeAirStopDice()
    { return 2; }

// exertion in the stale air forces a stop after 2d6 rounds (the die sides).
inline int dnaeAirStopSides()
    { return 6; }

// recovery from gasping in the dead air takes 1d6 rounds (the die count).
inline int dnaeAirRecoverDice()
    { return 1; }

// recovery from gasping in the dead air takes 1d6 rounds (the die sides).
inline int dnaeAirRecoverSides()
    { return 6; }

// virtually all items of value were stripped from the city by the duergar
// upon their emigration; stone furniture is common, but the few surviving
// wooden items are fragile and quickly crumble under pressure, and the side
// caverns that once raised edible fungus and corralled cave-pigs and other
// livestock now hold only a thick layer of dust over dry soil.
inline bool dnaeStrippedFragile()
    { return true; }

// a secret trapdoor in the floor of the great palace hall leads to a large
// smithy: great furnaces long since extinguished line the walls, and the
// massive black anvil at the center radiates strong magic - it is the forge
// of power of the duergar.
inline bool dnaeForgeOfPower()
    { return true; }

// the massive black anvil at the center of the secret smithy weighs 25,000
// gp.
inline int dnaeAnvilWeightGp()
    { return 25000; }

// any weapons or armor hammered into shape upon the duergar forge-of-power
// anvil gain an enchantment bonus of +1; this cannot be used to improve an
// existing weapon.
inline int dnaeAnvilBonus()
    { return 1; }

// when the anvil is combined with the hammer of substance wielded by a
// dwarven or duergar smith, weapons of +2 enchantment can be created (the low
// bound).
inline int dnaeAnvilHammerLow()
    { return 2; }

// with the hammer of substance, weapons of even +3 enchantment can be created
// (the high bound).
inline int dnaeAnvilHammerHigh()
    { return 3; }

// ---- the Area 7 Grand Canyon section ----

// the yawning chasm of the Grand Canyon stretches over ten miles in length.
inline int dnaeCanyonLenMiles()
    { return 10; }

// the canyon is fully a mile wide.
inline int dnaeCanyonWidthMiles()
    { return 1; }

// the naturally arching ceiling is about 200 feet high at the point where the
// tunnel from Area 6 enters.
inline int dnaeCanyonCeilFt()
    { return 200; }

// the canyon walls gradually grow closer together as they descend, meeting in
// a boulder-and-rubble-filled gorge over a mile below.
inline int dnaeGorgeDepthMiles()
    { return 1; }

// the canyon was originally excavated by water erosion - a great river once
// cut a path through it, and the same shift in water table that dried up the
// duergar wells caused the river to cease flowing; it is now similar to a
// dead cave with few formations, kept less dusty by faint circulating
// breezes, and it has withstood many a tumultuous earthquake.
inline bool dnaeCanyonErosionOrigin()
    { return true; }

// the canyon walls are cracked and riddled with ledges, chimneys and other
// irregularities, but the rock is old and generally stable - not likely to
// break off when climbed; no bridges cross it at this height.
inline bool dnaeStableWalls()
    { return true; }

// about 3,000 feet below the access-tunnel level, another series of caverns
// enters the canyon on one side and continues out the other.
inline int dnaeLowerCavernsDepthFt()
    { return 3000; }

// the lower cavern series lies about two miles south of the upper-level
// tunnels, so characters scaling straight down the walls do not discover
// them.
inline int dnaeLowerCavernsSouthMiles()
    { return 2; }

// the canyon walls are pockmarked regularly with limestone caves, some of
// them as deep as 300 feet.
inline int dnaeCaveMouthDeepFt()
    { return 300; }

// the limestone cave mouths occur at intervals of about 500 feet above,
// below, and to the sides of each other - sometimes closer, sometimes more
// widely separated.
inline int dnaeCaveMouthIntervalFt()
    { return 500; }

// at the cavern ceiling several narrow vertical shafts lead up to join a
// major tunnel connecting with the sewer system of the large surface city;
// they range from 1-3 feet in diameter (the low bound).
inline int dnaeShaftDiaLowFt()
    { return 1; }

// the vertical shafts range from 1-3 feet in diameter and often climb
// straight up, of little use to any creatures except bats (the high bound).
inline int dnaeShaftDiaHighFt()
    { return 3; }

// bats inhabit the canyon in great numbers, most of the harmless normal
// varieties; the several hundred mobats subsist off the former but also
// aggressively attack large warm-blooded intruders, though not all together.
inline bool dnaeBatSwarms()
    { return true; }

// several hundred mobats live in the canyon and aggressively attack large
// warm-blooded intruders, but in groups of 2d6 at a time (the die count).
inline int dnaeMobatGroupDice()
    { return 2; }

// the mobats attack in groups of 2d6 at a time (the die sides).
inline int dnaeMobatGroupSides()
    { return 6; }

// several of the small caves branching off the canyon are the lairs of cave
// fishers that strike any flying or climbing creatures within reach; the
// canyon bottom is regularly scoured by a pair of giant slugs, many smaller
// side caves house giant centipedes, and carrion crawlers regularly move up
// and down the walls.
inline bool dnaeCanyonPredators()
    { return true; }

// the cloakers of the highest side caves are 50% likely to be attracted if
// the mobats attack an intruder; they fly to the combat scene and wait for
// the bats to drive off or claim their victim.
inline int dnaeCloakerAttractPct()
    { return 50; }

// the cloaker community numbers about two dozen individuals; they do not
// attack as a group, and the number used should be balanced with the levels
// of the player characters.
inline int dnaeCloakerCount()
    { return 24; }

// the canyon has a plentiful supply of fresh air from its access tunnels, but
// water is confined to a number of stagnant pools among the rocks at the
// bottom - some very large and deep, none fed by fresh flowing water.
inline bool dnaeStagnantPools()
    { return true; }

// the stagnant canyon-bottom pools receive no fresh flowing water; characters
// who drink from them have a 50% chance of contracting a disease, as in the
// cause disease spell effect.
inline int dnaePoolDiseasePct()
    { return 50; }

// food supplies are limited to the creatures living here and a few lichens
// and fungi growing in narrow niches upon the canyon walls.
inline bool dnaeCanyonFood()
    { return true; }

}   // namespace rules
