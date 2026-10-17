// =========================================================================================
// Adnd1 - rules/dsgenv.h
// THE DSG UNDERGROUND ENVIRONMENT OPENER, R530: printed pp. 65-68 (pdf 66-69)
// - the first DM-section child, the underground environment chapter: the
// why-an-ecosystem justifications (defense: the dungeon safer than a castle -
// impervious to aerial attack, the earthquake target hard to identify at
// depth, held by a smaller group since access is limited, no wall garrison so
// a reserve against break-ins, the burrowers menacing but rarely marshalled;
// the drow and duergar survival through defensibility; mining: the dwarven
// and gnomish economies, the mines converted to fortresses, prisons and
// lairs, the burrowing monsters passageways, the connected limestone caverns
// many over 100 miles long; gravity: the centuries of creatures falling into
// holes and adapting to the dark world), the features of the underground game
// (the DM control over narrow options, the essential encounter in a central
// room, the plannable monster tactics with the rigged alarms and ambushes
// undoable by creative play, the beginners decision ease with the doorway and
// 10-foot-corridor defense, the danger atmosphere, the common fears, the
// alienness and wonder, the frontier below the feet with its exploration,
// scouting, plunder and conquest missions, and the back-to-basics variety),
// the nature of the underground environment and its denizens (the precarious
// balance of power upset by PC arrival, the land more precious than on the
// surface, the evil tendency with the drow and kuo-toa war banishment, the
// lower-planes theory and the oldest mind flayers and derro, the humorless
// philosophy with the functional art and the punished waste, the timelessness
// and the old-age-before-execution tale, the stubborn conservatism, the
// depth-shaped resources with the mile-floated wood and the raided food and
// slaves, the depth-shaped alienness, the sunless food chain with its fungi,
// rothe and cave pigs, the inedible stone-eaters, the minor scavengers, the
// nocturnal raiders, and the natural oxygen circulation through arctic shafts
// and geothermal heat), and a brief history of underground cultures (the five
// ancient cultures - the jermalaine tunnels, the myconid coexistence, the
// aboleth Darksea cities, the evicting cloakers, the mind flayer dominion
// checked only by low reproduction; the Alignment Wars with alignment-chosen
// sides and the seaborne kuo-toa; the evil halted at the sunlit tunnel
// mouths; the defeat, the retreat of drow and duergar and kuo-toa and the
// faded alliance; the immigrant niches; the interplanar doors with the Plane
// of Earth strongest; the gem-lusting svirfneblin, the stone-working pech and
// the interbred derro; and the savage wars of today with the isolated pockets
// between monster stretches)
// census 453 -> 454.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~8226-8860) with the pdf Acrobat-Capture layer as the second read (idx
// 149-162 = the printed pp. 65-69 windows); the compiled-tables appendix has
// no reprint of this prose. A CLEAN-READ ROUND: both machine reads agree on
// every load-bearing number - the 100-mile limestone caverns, the 10-foot
// corridor, the mile-or-more floated wood, and the five ancient cultures; the
// only garbles are the standing glyph classes (the Cyrillic-lead djvu noise
// on the DM table of contents, a page this round does not pin). SEAMS: the
// Monster Manual burrowers (umber hulk, landshark, xorn), the Monster Manual
// underground cultures (jermalaine, myconid, aboleth, cloaker, mind flayer,
// pech, derro, svirfneblin), the DMG inner planes (the Plane of Earth gate),
// and the R503 re-grain (this child of the DM section). THE DM SECTION OPENS
// with this round; the gap children for the underground geography (p. 69),
// the theories of the underground (pp. 70-71) and the cultures of the
// underdark (pp. 73-74) follow in later rounds. Nothing auto-credits.
//
// A prose round: no tables pin. The numbers pin as consts per the R508
// convention: the 100-mile limestone caverns, the 10-ft corridor defense, the
// mile-floated wood, and the five ancient cultures. The rest pins as prose
// bools: the ecosystem justifications (the castle comparison, the burrowers,
// the depth, the garrison, the drow and duergar survival, the mining, the
// gravity), the features of the game (the DM control, the essential
// encounter, the monster tactics, the beginners ease, the danger, the fears,
// the alienness, the frontier, the back to basics), the nature of the
// environment (the balance, the land, the evil tendency, the lower-planes
// theory, the philosophy, the resources, the alienness, the food chain, the
// oxygen), and the brief history (the five cultures, the Alignment Wars, the
// retreat, the niches, the plane doors, the later arrivals, the wars of
// today). The MM/DMG/R503 seams are noted; nothing auto-credits.
//
namespace rules {

// ---- the why-an-ecosystem section ----

// a dungeon is a more secure position than a castle: virtually impervious to
// aerial attacks, hard to target with earthquake spells when it lies well
// beneath the ground, and held by a much smaller group of defenders because
// access is limited.
inline bool dnugDungeonSaferThanCastle()
    { return true; }

// burrowing creatures such as umber hulks, landsharks and xorn still menace
// dungeons, but are rarely marshalled into an army - and such a force would
// threaten a castle as much as a dungeon.
inline bool dnugBurrowersNoArmy()
    { return true; }

// a dungeon can be built at any depth; the farther from the surface, the more
// effort an attacking army must spend excavating an access, unlike a castle
// with only a few dozen feet of stone.
inline bool dnugDepthBlocksExcavation()
    { return true; }

// dungeon-dwellers need not garrison a wall, so they are much more likely to
// hold a reserve of troops against a sudden break-in.
inline bool dnugNoGarrisonReserve()
    { return true; }

// this defensibility probably accounts for the survival of the drow and
// duergar: after near-total defeat on the surface they slunk into the
// Underdark, withstood the final assaults and prospered - almost unassailable
// below, but little threat above, an uneasy balance.
inline bool dnugDefensibilitySavedDrow()
    { return true; }

// the mining economies of dwarves and gnomes account for great excavation,
// and many old mines became fortresses, prisons or monster lairs; burrowing
// monsters like purple worms, umber hulks and ankhegs create passageways
// smaller creatures can use.
inline bool dnugMiningExcavation()
    { return true; }

// gravity populates the depths: creatures fell into surface holes for
// centuries, and where food and essentials existed they prospered, forgot the
// sunlit ways and adapted to the dark world.
inline bool dnugGravityPopulates()
    { return true; }

// thousands of huge natural limestone caverns, many of them over 100 miles
// long, are now connected by the tunnels of miners and burrowing monsters.
inline int dnugLimestoneMiles()
    { return 100; }

// ---- the features of the underground game section ----

// in the underground game the DM exerts great control over options and
// challenges: a room with two corridors gives the characters only three real
// options, so the DM prepares for only a few courses of PC action.
inline bool dnugDmControlNarrow()
    { return true; }

// an essential encounter can be forced by placing it in a centrally located
// room PCs are almost certain to visit regardless of the routes they choose.
inline bool dnugEssentialEncounter()
    { return true; }

// monster and NPC tactics can be planned in advance because approach
// directions are limited - alarms rigged and ambushes set with confidence -
// though intelligent and creative play can undo many a DM-rigged surprise.
inline bool dnugMonsterTacticsPlanned()
    { return true; }

// the narrowness of options also eases the players decision-making,
// appreciated by beginners in particular, and confining terrain simplifies
// combat tactics.
inline bool dnugBeginnersDecisionEase()
    { return true; }

// outnumbered PCs hold a better defensive position in a doorway or a
// 10-foot-wide corridor than they could in a wilderness clearing.
inline int dnugCorridorFt()
    { return 10; }

// the darkness, tight passageways and distance from succor create an
// atmosphere of intensity and excitement virtually unheard-of in a wooded or
// city setting.
inline bool dnugDangerAtmosphere()
    { return true; }

// the underground touches fears common to us all - caves and old mines where
// only experts dare tread, the real-life dangers of volcanoes and
// earthquakes, and the mythological sources of evil below - letting players
// role play the forbidden reaches at no risk save an imaginary character.
inline bool dnugCommonFears()
    { return true; }

// the players unfamiliarity with the underground adds to the sense of wonder;
// the DM needs a great deal of information to run it as a believable and
// interesting locale even while it stays mysterious to the players.
inline bool dnugAliennessWonder()
    { return true; }

// both meanings of frontier apply underground - where civilization ends and
// where one government or culture yields to another - and the frontier below
// the feet of a civilized area is often more accessible, and perhaps more
// challenging, than the farthest national boundaries.
inline bool dnugFrontierBelowFeet()
    { return true; }

// expanding the subterranean frontier means missions of exploration,
// scouting, plunder and conquest; the knowledge carried back is valuable to
// the ruler, and the desire to expand a frontier is often motivation enough
// for an expedition.
inline bool dnugFrontierMissions()
    { return true; }

// underground adventure need not be a routine of slaying and looting:
// Underdark civilizations as old or older than any surface culture offer
// encounters as sophisticated as the court of the High King, and bored
// players can be drawn back by a mature story line - variety in settings,
// stories and conflicts being crucial to interest.
inline bool dnugBackToBasics()
    { return true; }

// ---- the nature of the underground section ----

// whenever PCs intrude into the crowded underground realms, the DM should
// find the cultures in a precarious balance of power - unstable, so the
// arrival of surface characters may be enough to upset the equilibrium.
inline bool dnugPrecariousBalance()
    { return true; }

// underground races stake and defend territorial claims fiercely; land is
// even more precious below because solid rock often prevents a displaced race
// from moving freely elsewhere.
inline bool dnugLandMorePrecious()
    { return true; }

// the deep-dwellers show a tendency toward evil: the drow and kuo-toa were
// driven underground losing an ancient war against the united surface forces,
// evil banished to the less appealing locations - though evil remains on the
// surface too, and alignments drifted over time.
inline bool dnugEvilTendency()
    { return true; }

// another theory links the deep cultures to the lower planes, but the evil
// Underdark worship may follow a previously existing alignment rather than
// the depth itself - most meritorious for the oldest races with no surface
// period, the mind flayers and derro.
inline bool dnugLowerPlaneTheory()
    { return true; }

// underground cultures have little appreciation for humor: the tons of rock
// overhead and the chances of asphyxiation or flood make life very serious,
// their art almost universally portrays death as omnipresent, and laughter is
// almost unheard of in the deep reaches.
inline bool dnugNoHumor()
    { return true; }

// many underground races are chaotic in nature, but that alignment shows
// mainly in large-group organization; individuals, lawful or chaotic, are
// very disciplined, the scarcity of resources - most notably air - forcing
// care.
inline bool dnugDisciplinedIndividuals()
    { return true; }

// underground art serves a function beyond merit: sculpture worked into
// support columns and arches, songs carrying solemn vows and formal
// introductions, and encyclopedias ranked among the highest forms of
// literature.
inline bool dnugFunctionalArt()
    { return true; }

// waste of food, material or energy is deplored and often punished severely;
// air is a valuable resource, and control of its use - particularly regarding
// fires - is a common feature of underground law.
inline bool dnugWastePunished()
    { return true; }

// with no day into night or summer into winter, a timelessness marks
// underground philosophy - the aging of creatures and plants the truest
// indicator, and even that meaning little; the tale is told of a captured
// surface man sentenced to immediate execution who died of old age in his
// cell first.
inline bool dnugTimelessness()
    { return true; }

// creatures raised underground are very stubborn and resistant to change; the
// most conservative surface government would seem radical by comparison -
// solid rock around them seriously limits the options when decisions are
// required.
inline bool dnugStubbornConservative()
    { return true; }

// surface resources are common only in the top several hundred feet of the
// Underdark, except where gravity moves them deeper; wood is the most common,
// floated down waterways or harvested from rare solid-stemmed woody fungi.
inline bool dnugDepthShapesResources()
    { return true; }

// wood, the most common surface resource carried underground, can be floated
// a mile or more below via streams and rivers of sufficient depth - though
// few waterways flow hard enough to carry it without jamming.
inline int dnugWoodFloatMiles()
    { return 1; }

// food and slaves are additional resources harvested by the denizens - slaves
// and food on the hoof moving under their own power; most underground
// creatures grow no crops and keep no herds, preferring raids on surface food
// stores.
inline bool dnugFoodSlavesRaided()
    { return true; }

// the farther below the surface, the less human the cultures: the drow,
// duergar and svirfneblin homelans lie very deep, while the much more alien
// mind flayers and aboleths dwell deeper still.
inline bool dnugDepthShapesAlienness()
    { return true; }

// the underground food chain begins with fungi, lichens and molds that grow
// without sunlight; herbivores like rothe and cave pigs subsist on them, and
// intelligent creatures domesticate the herbivores to insure fresh meat,
// while unintelligent creatures eat what they can catch.
inline bool dnugSunlessFoodChain()
    { return true; }

// unusual life forms subsist on stone, gems or minerals; quite alien, they
// generally stand outside the food chain and are believed inedible to
// carnivorous or omnivorous hunters.
inline bool dnugStoneEatersInedible()
    { return true; }

// the scavengers living off carrion, garbage and offal occupy a very minor
// place in the food chain, since few carnivores find them palatable.
inline bool dnugScavengersMinor()
    { return true; }

// creatures living close enough to emerge and return in a single night prefer
// supplementing their supplies with nocturnal raids for surface plants and
// animals.
inline bool dnugNocturnalRaiders()
    { return true; }

// oxygen must be circulated even to the deepest reaches: cold air sinks into
// huge arctic shafts, geothermal heat warms it and sends it rising through
// the domain until it emerges at entrances - a natural process needing no
// forced movement, though stagnant pockets occur unless circulation is
// improved.
inline bool dnugOxygenCirculation()
    { return true; }

// ---- the brief history section ----

// five distinct cultures are identified as dating back to ancient times in
// the underground: the jermalaine, the myconids, the aboleth, the cloakers
// and the mind flayers.
inline int dnugAncientCultures()
    { return 5; }

// the jermalaine spread through virtually all the underground realms and
// created most of the small narrow tunnels that first connected widely
// separated caverns - too small for most creatures to pass, later expanded
// and organized by other dwellers.
inline bool dnugJermalaineTunnels()
    { return true; }

// the myconids, basically peaceful but capable of defending themselves
// against the jermalaine, learned to coexist with little friction - their
// differing food sources meant no fight for the same ecological niche.
inline bool dnugMyconidCoexistence()
    { return true; }

// the aboleth, evil creatures of extremely high Intelligence and advanced
// culture, prefer the dark subterranean waterways; their population
// concentrates in sprawling cities on the floor of the Darksea, developed
// with little interference - but ineffective outside water, unable to extend
// their influence.
inline bool dnugAbolethDarksea()
    { return true; }

// the cloakers have dwelt underground since time immemorial, so alien few
// other creatures can communicate with them; they move into areas excavated
// by others and drive the original inhabitants away with deadly persistence.
inline bool dnugCloakersEvict()
    { return true; }

// the mind flayers once controlled vast reaches and were feared throughout
// the lands of darkness, none of the original races able to stand up to them;
// only their very low reproductive rate prevented control of the entire
// Underdark, and race wars have since driven them into deep hidden realms.
inline bool dnugIllithidDominion()
    { return true; }

// the Alignment Wars were a single grand conflict spanning centuries with
// occasional truces of a few decades, characterized by great interracial
// cooperation and intraracial combat - the sides determined by alignment, not
// race, with the kuo-toa choosing evil in the seas.
inline bool dnugAlignmentWarsSides()
    { return true; }

// the evil creatures bore an intense dislike for the sun, so their expansion
// halted at the mouths of their tunnels and caves - rarely would one venture
// onto the surface even in the dark of a moonless night, and rarely would a
// surface-dweller dare the world below.
inline bool dnugEvilHaltedAtSun()
    { return true; }

// the forces of good slowly drove evil back until the survivors acknowledged
// defeat and bitterly sought shelter underground: the drow and duergar moved
// below in great numbers, their war skills overcoming the prior tenants; the
// kuo-toa entered the subterranean waterways; the tired victors abandoned the
// pursuit and the grand alliance faded.
inline bool dnugDefeatAndRetreat()
    { return true; }

// the newly arriving races carved out niches: the mind flayer and cloaker
// domains were severely reduced as drow and duergar seized caverns and
// tunnels, the kuo-toa claimed many small dispersed areas, the jermalaine and
// myconids stayed prosperous though somewhat crowded, and only the serene
// aboleths were left undisturbed.
inline bool dnugImmigrantNiches()
    { return true; }

// the excavation of many cubic miles of rock, coupled with powerful
// spell-casters, opened gateways to other planes: the Plane of Earth
// connection the strongest, its denizens callable at will, doors to the lower
// planes developing, and doors to the Planes of Fire and Water where volcanic
// rock bubbled or waterways flowed - an unusually high population of a plane
// denizens often betraying a nearby gate.
inline bool dnugPlaneOfEarthStrongest()
    { return true; }

// the deep gnomes, or svirfneblin, adapted completely underground through
// lust for gems and are one of the few cultures with tendencies toward good;
// the pech arrived from perhaps the Plane of Earth with unsurpassed
// stone-working skill; and the derro, most recent, grew from duergar
// interbreeding with vaguely human races.
inline bool dnugSvirfneblinGood()
    { return true; }

// savage warfare has erupted in the crowded realms since the retreat and
// continues with the same savagery today - once-overpopulated areas now
// desolate, populations whittled to isolated pockets of drow, duergar,
// myconids, derro, pech, cloakers, mind flayers and jermalaine between
// uninhabited or monster-inhabited stretches, while the aboleth keep age-old
// control of the still waters of the Darksea.
inline bool dnugSavageWarsToday()
    { return true; }

}   // namespace rules
