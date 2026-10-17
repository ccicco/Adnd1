// =========================================================================================
// Adnd1 - rules/dsgarea12.h
// THE DSG DEEPEARTH AREAS 24-25, R545: printed p. 94 (pdf 95) - the
// individual area key crosses the gray dwarf domain and the shaft: Area 24
// the Domain of the Duergar (the largest concentration of gray dwarves in
// Deepearth, nearly a hundred natural caves widened and stairwayed; the
// living caves with their plentiful flowing water, the water-filled chambers
// with ledged walkways, the drought-proof dammed reservoirs; the central
// council cavern; the 30-foot navigable outflow stream with its dry walkway;
// the 8,000 duergar with their rothe herds; the second-class derro tenants
// under protection; the hundreds of demoralized slaves - humans, goblins,
// svirfneblin, drow - with a 25% escape-join chance; the un-eradicable giant
// bats; the Grand Canyon air and the cut air ducts; the southwestern
// slave-worked mines of iron, copper and gold; the fine-art metal-working and
// the gold sculptors - 1d6 x 100 gp of statuary per residence, six times that
// in the larger homes, 2d6 x 1,000 gp in the council chambers and inns,
// life-size 20,000-gp statues in the largest chamber, each worth 1d4 + 1
// times its gold intact on the surface; and the red-fungus breweries with
// their pungent potent ale and the one-or-two inns per cavern), and Area 25
// the Windpipe (the six living caves with spectacular formations joining at
// the excavated chamber, each with an 80-foot, miles-long central room; the
// high-level drow outpost - 4th-or-higher fighters with a 5th-or-higher
// magic-user and cleric - patrolling and slaving; the doombats, piercers,
// oozes, jellies, slimes, lichens, basidironds, rats and crawlers; the 50%
// polluted pools with one or two pure sources per cave; and the shaft itself
// - about 20 feet wide, 20 miles to the mountain crevasse, door-sized entry,
// alternating blasts: one turn per hour roaring upward to ride lying down,
// four turns inactive, one turn down, timing varying as much as 50%; the
// journey five rounds up to Area 28 and eight down, the failed Intelligence
// Check halting a descent for 6d6 of falling damage).
// census 468 -> 469.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~12082-12255) with the pdf Acrobat-Capture layer as the second read
// (capture idx 214 = the printed p. 94 window carrying Area 24 in full and
// the Area 25 head, idx 216 head = the printed p. 95 window carrying the
// windpipe body); the compiled-tables appendix has no reprint of this prose.
// A CLEAN-READ ROUND: both machine reads agree on every load-bearing number -
// the hundred caves, the 30-ft outflow, the 8,000 duergar, the 25% slave
// chance, the 1d6x100/6x/2d6x1,000/20,000-gp/1d4+1 gold ladder, the six caves
// with 80-ft chambers, the 4th/5th-level drow, the 50% polluted pools, the
// 20-ft/20-mile shaft, the one-turn up/four-turn lull/one-turn down cycle at
// 50% variance, the five-and-eight-round journeys and the 6d6 fall; the only
// garbles settled cross-read (the capture ld6, 2d6, ld4+1 and ld12 for the
// djvu dice, the djvu realms-o!for the capture realms of). SEAMS: the R518
// water travel (the navigable outflow and the drow waterways ahead), the
// Monster Manual denizens (the duergar, derro, drow, rothe, doombats,
// basidironds), the R521-R522 mining (the slave-worked iron-copper-gold), the
// PHB Intelligence Check, and the gold-value economy. A ZERO-FLIP ROUND: the
// pp. 75-98 Deepearth child remains open until the setting lands in full (the
// R527/R533-R544 precedent - the gap report is NOT in the git add). Nothing
// auto-credits.
//
// A procedural-plus-prose round: no tables pin. The numbers pin as consts per
// the R508 convention - the cave count, the outflow width, the duergar
// population, the slave escape percentage, the gold-value ladder (residence
// dice-sides-multiplier, the larger-residence multiplier, the public
// dice-sides-multiplier, the statue value, the intact dice-sides-base
// triple), the windpipe cave count and chamber height, the drow fighter and
// caster levels, the pool pollution percentage and pure-source minimum, the
// shaft width and miles, the blast-cycle turns, the timing variance
// percentage, the journey rounds up and down, and the fall dice, with the
// 1d6x100, 2d6x1,000, 1d4+1 and 6d6 pinned as count-sides(-multiplier/base)
// const triples or pairs. The geography, denizens, resources and
// unique-features prose pins as bools for both areas. The
// water-travel/MM/mining/PHB seams are noted; the Deepearth child stays open;
// nothing auto-credits.
//
namespace rules {

// ---- the Area 24 Duergar Domain section ----

// this large network of natural caverns is the home of the largest
// concentration of gray dwarves, or duergar, in Deepearth; the duergar have
// widened some passages and built stairways.
inline bool dnanGrayDwarfHome()
    { return true; }

// nearly a hundred caves make up the domain of the duergar.
inline int dnanCaveCount()
    { return 100; }

// these are living caves containing plentiful supplies of fresh, flowing
// water; several are almost completely water-filled, but even these have
// small air spaces near the top with ledged walkways so the gray dwarves can
// move through them.
inline bool dnanLivingCaves()
    { return true; }

// the caves have been dammed to control outflow so the dwarves maintain a
// large water supply even during periods of drought.
inline bool dnanDammedReservoirs()
    { return true; }

// like the deep gnome caves, the duergar caves contain large central open
// areas with extensive networks of dungeons and tunnels excavated for living
// quarters along the sides, plus a large central cavern established as a
// council chamber.
inline bool dnanCentralCaverns()
    { return true; }

// the east tunnel serves as the outflow for most of the area's water; a dry
// walkway runs beside the stream, allowing unimpeded foot travel.
inline bool dnanOutflowWalk()
    { return true; }

// the stream in the outflow tunnel is about 30 feet wide and is navigable by
// small boats.
inline int dnanOutflowWideFt()
    { return 30; }

// the duergar, the main inhabitants of the area, number about 8,000.
inline int dnanDuergarPop()
    { return 8000; }

// in several small attached caves the gray dwarves allow small communities of
// derro to live - treated as second-class citizens, they tolerate the
// arrangement for the protection of the huge duergar population.
inline bool dnanDerroTenants()
    { return true; }

// hundreds of slaves are imprisoned in small, poorly-ventilated caverns among
// the dwellings - humans, goblins, svirfneblin and drow, demoralized and
// listless.
inline bool dnanSlaveCaverns()
    { return true; }

// there is a 25% chance that a given group of slaves might be persuaded to
// join in an escape attempt.
inline int dnanSlaveEscapePct()
    { return 25; }

// many giant bats live in ceiling niches of the duergar caverns; despite
// everything the duergar can do they remain, preying chiefly on rothe but
// seizing a duergar, derro or slave when the opportunity arises.
inline bool dnanGiantBats()
    { return true; }

// like the svirfneblin, the gray dwarves maintain large herds of rothe.
inline bool dnanRotheHerds()
    { return true; }

// proximity to the Grand Canyon insures an adequate air supply, and the
// duergar have cut many air ducts through the rocks to aid circulation; even
// in drought the reservoir caverns hold enough water to last the gray dwarves
// for several years.
inline bool dnanAirDucts()
    { return true; }

// at the southwestern end of their domain the duergar run an ambitious mining
// operation - a three-dimensional network of shafts and tunnels extending
// many miles, worked almost exclusively by slaves.
inline bool dnanSlaveMines()
    { return true; }

// the duergar mine iron, copper and gold.
inline bool dnanIronCopperGold()
    { return true; }

// duergar metal-working is a fine art - tools, weapons and armor of the
// highest quality; gold is not used for such mundane purposes, but a cadre of
// highly skilled sculptors casts pure molten gold from stone models and molds
// into exquisite statuary.
inline bool dnanGoldSculptors()
    { return true; }

// an average duergar residence contains 1d6 x 100 gp worth of small statuary
// (the die count).
inline int dnanResGoldDice()
    { return 1; }

// the average residence statuary is 1d6 x 100 gp (the die sides).
inline int dnanResGoldSides()
    { return 6; }

// the average residence statuary is 1d6 x 100 gp (the multiplier).
inline int dnanResGoldMult()
    { return 100; }

// larger residences may have up to six times the average residence value.
inline int dnanLargeResMult()
    { return 6; }

// in public areas such as the council chambers or inns, gold sculptures are
// worth 2d6 x 1,000 gp (the die count).
inline int dnanPubGoldDice()
    { return 2; }

// the public-area sculptures are worth 2d6 x 1,000 gp (the die sides).
inline int dnanPubGoldSides()
    { return 6; }

// the public-area sculptures are worth 2d6 x 1,000 gp (the multiplier).
inline int dnanPubGoldMult()
    { return 1000; }

// the largest chamber holds life-size solid gold statues of many prominent
// figures from the race's past, each containing about 20,000 gp worth of
// gold.
inline int dnanStatueGp()
    { return 20000; }

// a statue returned to the surface intact is worth 1d4 + 1 times its gold
// content (the die count).
inline int dnanIntactDice()
    { return 1; }

// the intact surface value is 1d4 + 1 times the gold content (the die sides).
inline int dnanIntactSides()
    { return 4; }

// the intact surface value is 1d4 + 1 times the gold content (the base).
inline int dnanIntactBase()
    { return 1; }

// duergar breweries use a red fungus rather than grain, producing a pungent
// and potent ale common among the gray dwarves; each cavern has at least one
// or two side caves hollowed out as inns, well-attended at all times, and
// like the deep gnomes the duergar trade their products with neighboring
// cultures.
inline bool dnanFungusBrew()
    { return true; }

// ---- the Area 25 Windpipe section ----

// several large caverns provide alternative routes through this area, joining
// at their northern extremities into the huge excavated chamber that contains
// the windpipe.
inline bool dnanWindRoutes()
    { return true; }

// the six caves leading to the windpipe are living caves with many
// spectacular formations.
inline int dnanWindCaves()
    { return 6; }

// each windpipe cave includes a vast central chamber 80 feet high or higher.
inline int dnanWindChamberHtFt()
    { return 80; }

// the central chambers of the windpipe caves run several miles long, linked
// by much narrower connecting passages to the excavated tunnel to Area 26 and
// the circular windpipe chamber.
inline bool dnanMilesLongCham()
    { return true; }

// a large outpost of drow lives in the windpipe chamber, and dark elf patrols
// are common in the connecting caves; because the windpipe allows access to
// their realms below, the outpost drow are of high level and morale, and they
// take prisoners as slaves from parties they can easily overpower.
inline bool dnanDrowOutpost()
    { return true; }

// all dark elves encountered in the area are fighters of 4th level or higher.
inline int dnanDrowFighterLvl()
    { return 4; }

// the drow outpost includes a magic-user and a cleric of 5th level or higher.
inline int dnanDrowCasterLvl()
    { return 5; }

// despite the drow patrols the caverns host doombats and piercers among the
// ceiling stalactites, oozes, jellies and slimes among the small pools,
// lichen clusters on the floors, basidironds among harmless fungus, and giant
// rats and carrion crawlers moving restlessly cave to cave.
inline bool dnanWindFauna()
    { return true; }

// the pools are subject to infrequent flowage, and about 50% of them have
// been polluted by noxious creatures or their droppings.
inline int dnanPoolPollutePct()
    { return 50; }

// each of the six large caves has at least one or two sources of pure water
// (the minimum).
inline int dnanPureSourcesMin()
    { return 1; }

// the windpipe is a smooth shaft through the earth stretching from the lowest
// realms of Deepearth to a high mountain crevasse; it accounts for most of
// the ventilation of the drow realms and also serves as a means of
// transportation, its entry in Area 25 a door-sized opening in the side of
// the shaft.
inline bool dnanWindShaft()
    { return true; }

// the windpipe is about 20 feet wide.
inline int dnanShaftWideFt()
    { return 20; }

// the windpipe stretches to a high mountain crevasse some 20 miles distant.
inline int dnanShaftMiles()
    { return 20; }

// the windpipe is subject to alternating blasts of air that blow up from the
// depths and then back down.
inline bool dnanAlternatingBlasts()
    { return true; }

// for approximately one turn per hour the windpipe fills the surrounding
// caverns with a roaring sound as air blasts upward from the heart of
// Deepearth; during these spurts a character can step into the shaft, lie
// down, and be propelled upward, slowing or reversing his climb by changing
// orientation - a character standing upright falls at a rapid speed.
inline int dnanUpBlastTurns()
    { return 1; }

// the windpipe is inactive for about four turns per hour, unsuitable for
// transportation.
inline int dnanInactiveTurns()
    { return 4; }

// the windpipe carries a downward blast of air for another turn per hour,
// also unsuitable for transportation.
inline int dnanDownBlastTurns()
    { return 1; }

// the exact timing between blasts is a matter of guesswork and luck, since it
// varies as much as 50%.
inline int dnanTimingVaryPct()
    { return 50; }

// the journey from Area 25 to Area 28 takes five rounds.
inline int dnanJourneyUpRounds()
    { return 5; }

// the reverse journey from Area 28 to Area 25 takes eight rounds, so bad
// timing - and fatalities - is not unheard of.
inline int dnanJourneyDownRounds()
    { return 8; }

// the drow have become skilled at using the airflow between Areas 28 and 25;
// characters new to the experience must make successful Intelligence Checks
// to stop correctly - for upward travelers failure simply means reversing
// course.
inline bool dnanWindSkill()
    { return true; }

// failure to halt downward movement in the windpipe results in falling damage
// of 6d6 points (the die count).
inline int dnanWindFallDice()
    { return 6; }

// the windpipe fall deals 6d6 damage (the die sides).
inline int dnanWindFallSides()
    { return 6; }

}   // namespace rules
