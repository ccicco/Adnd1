// =========================================================================================
// Adnd1 - rules/dsgarea14.h
// THE DSG DEEPEARTH AREAS 28-29, R547: printed pp. 96-97 (pdf 97-98) - the
// individual area key descends to the drow and the dark: Area 28 the Realm of
// the Drow (the vast realm of excavated caverns linking large living caves,
// the high point of drow culture; the perfectly circular council chamber over
// a mile in diameter, its dome 1,000 feet from the floor on massive columns,
// the central vertical shaft to the matriarchs' hall accessible only by
// flight or levitation; the hundreds of linking caverns and the built cities
// - buildings erected in the caverns like surface communities; the plentiful
// water, the huge reservoirs and the placid waterways where boat travel
// rivals walking; the many levels joined by meticulously sculpted passages
// and elegant spiral stairways; the miniature council refuges for drow of 4th
// level or higher where levitation is universal, rope ladders lifting the
// rest in emergency; the more than 12,000 drow with their rothe and cave
// pigs; the windpipe's fresh air and the sages' pressure theory; the
// meticulously clean water, the fungus-farm caverns with their slight
// surplus, the strict population control; the mines of iron, copper, silver,
// gold, adamantite and mithril; and the city architecture - soaring columns,
// buttresses and huge domes lit by phosphorescent fungi, stone buildings with
// gold and silver ornament never structural), and Area 29 the Dark Realms
// (the spiderweb of living caves all leading down to the huge central
// chamber; the trickle that never floats a kayak, the water met as thick cold
// mud; the chamber with no less than 12 mouth passages each trickling mud
// into the monstrous reservoir - 300 feet deep, nearly a mile across, its
// level constant for centuries; the cloakers driven into a few dozen caverns,
// the mind flayers' evil third of the region, the well-defended derro
// communities; the unclaimed dark domains of slimes, oozes, jellies, animated
// fungi and scavengers; the hundred-plus Plane of Earth denizens - earth
// elementals, xorn, crysmal, galeb duhr, chaggrin, dao - clustered near their
// escape vortex; the stale foul-smelling air; the nearly unexploited gems and
// precious metals guarded by deadly hazards; and the mud whirlpool - the
// slow-motion elemental vortex to the Plane of Earth, its journey the Area 21
// procedure without heat damage but with breath held).
// census 470 -> 471.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~12362-12554) with the pdf Acrobat-Capture layer as the second read
// (capture idx 216 tail = the Area 28 head, idx 220 = the printed p. 97
// window carrying the Area 28 tail and the Area 29 head, idx 225 head = the
// Area 29 tail); the compiled-tables appendix has no reprint of this prose. A
// CLEAN-READ ROUND: both machine reads agree on every load-bearing number -
// the mile diameter, the 1,000-ft dome, the 4th-level refuge gate, the 12,000
// drow, the 12 mouth passages, the 300-ft mud depth and mile width, the
// hundred-plus earth denizens and the illithid third; the only garbles
// settled cross-read (the djvu Cyrillic-The and /evitation for the capture
// The and levitation). SEAMS: the R518 water travel (the drow waterways and
// boat travel), the Monster Manual denizens (the drow, rothe, cave pigs,
// cloakers, mind flayers, derro, xorn, crysmal, galeb duhr, chaggrin, dao and
// the oozes), the PHB levitate/fly and the Area 21 vortex procedure, and the
// R521-R522 mining (the drow mines and the unexploited veins). A ZERO-FLIP
// ROUND: the pp. 75-98 Deepearth child remains open until the setting lands
// in full (the R527/R533-R546 precedent - the gap report is NOT in the git
// add). Nothing auto-credits.
//
// A procedural-plus-prose round: no tables pin. The numbers pin as consts per
// the R508 convention - the dome height, the refuge level, the drow
// population, the mouth-passage count, the mud depth and the earth-denizen
// count, with the mile diameters and the illithid third pinned as bools of
// prose. The geography, denizens, resources and unique-features prose pins as
// bools for both areas; no dice appear in this round. The
// water-travel/MM/PHB/mining seams are noted; the Deepearth child stays open;
// nothing auto-credits.
//
namespace rules {

// ---- the Area 28 Drow Realm section ----

// this vast realm contains many excavated caverns linking a number of large
// living caves, and is the high point of drow culture in Deepearth.
inline bool dnapExcavatedRealm()
    { return true; }

// central to the drow realm is a perfectly circular chamber laboriously
// hollowed out from the rock, its ceiling rising to a dome supported by many
// massive columns, with a vertical shaft through the center leading to the
// matriarchs' council hall.
inline bool dnapCouncilChamber()
    { return true; }

// the circular council chamber is over a mile in diameter.
inline bool dnapMileDiameter()
    { return true; }

// the council chamber ceiling rises to a dome 1,000 feet from the floor.
inline int dnapDomeHtFt()
    { return 1000; }

// the matriarchs' council shaft is accessible only by flight or levitation.
inline bool dnapFlightOnlyShaft()
    { return true; }

// drow dwellings fill the hundreds of linking caverns; unlike the duergar or
// svirfneblin, the drow erect buildings in the caverns - communities that
// would resemble surface dwellers' but for the encompassing darkness and
// looming ceilings.
inline bool dnapBuiltCities()
    { return true; }

// water flows plentifully and the drow have created huge reservoirs; wide
// placid waterways connect many caverns, and boat travel is nearly as common
// as walking.
inline bool dnapWaterways()
    { return true; }

// the realm includes caverns on many different levels, but all connecting
// passages have been meticulously sculpted, with elegant spiral stairways
// circling shafts in the rock.
inline bool dnapSculptedPassages()
    { return true; }

// occasionally miniature versions of the matriarchs' council chamber allow
// access only to drow of 4th level or higher, since that is the level at
// which levitation ability becomes universal; in dire emergency rope ladders
// lift the rest of the population into these refuges, virtually impervious to
// attack.
inline bool dnapMiniRefuges()
    { return true; }

// the miniature council refuges admit only drow of 4th level or higher.
inline int dnapRefugeLvl()
    { return 4; }

// the drow leave no doubt as to their complete mastery of their realm.
inline bool dnapMastery()
    { return true; }

// more than 12,000 drow live here.
inline int dnapDrowPop()
    { return 12000; }

// the drow raise rothe and cave pigs for food and wool; a few rats and bats
// also dwell here, but other monsters are as rare as in the streets of a
// bustling surface city.
inline bool dnapRothePigs()
    { return true; }

// the bottom access tunnel to the windpipe provides a steady flow of fresh
// air; the drow do not understand the cause, but their sages postulate that
// small crust fluctuations cause great air-pressure changes in the narrow
// shaft.
inline bool dnapWindpipeAir()
    { return true; }

// water is abundant and the drow keep their water sources clean with
// meticulous dedication.
inline bool dnapCleanWater()
    { return true; }

// many large caverns are devoted exclusively to fungus growing, a food supply
// capable of feeding the populace with a slight surplus; population is
// strictly controlled, with imperfect babies ruthlessly killed at birth.
inline bool dnapFungusFarms()
    { return true; }

// the drow work a series of mines supplying their complex metalworking: iron,
// copper, silver, gold, and occasional finds of adamantite and mithril.
inline bool dnapDrowMines()
    { return true; }

// the drow cities are marvels of subterranean architecture - soaring columns,
// elegant buttresses and huge domes; despising sunlight, they employ numerous
// phosphorescent fungi among their dwellings to display the architecture.
inline bool dnapCityArchitecture()
    { return true; }

// all buildings consist primarily of expertly sculpted stone for smooth lines
// and a clean look; prominent offices or wealthy dwellings are embellished
// with gold and silver ornamentations, never structurally essential, only to
// enhance appearance.
inline bool dnapStoneOrnament()
    { return true; }

// ---- the Area 29 Dark Realms section ----

// this is a region of living caves; a map would resemble a spiderweb, with
// all the peripheral caves leading down toward a huge central cavern.
inline bool dnapSpiderwebCaves()
    { return true; }

// enough water trickles through to add lustre to the formations but never
// gathers volume enough to float even a kayak; the water is generally
// encountered as thick, cold mud.
inline bool dnapMudNotWater()
    { return true; }

// the central chamber has access to no less than 12 connecting passages, each
// carrying a slow trickle of mud.
inline int dnapMouthPassages()
    { return 12; }

// the chamber contains a monstrous reservoir of thick mud; though mud
// continually flows in, the level has remained constant for centuries.
inline bool dnapMudReservoir()
    { return true; }

// the mud reservoir measures some 300 feet deep.
inline int dnapMudDeepFt()
    { return 300; }

// the mud reservoir is nearly a mile across.
inline bool dnapMudMileAcross()
    { return true; }

// the alien culture of the cloakers, once prolific throughout Deepearth, has
// been driven into a narrow region of a few dozen caverns.
inline bool dnapCloakerRemnant()
    { return true; }

// the mind flayers hold more territory - roughly a third of this entire
// region falls under their evil dominion.
inline bool dnapIllithidThird()
    { return true; }

// several small communities of derro hold sway over localized caverns that
// are always well defended.
inline bool dnapDerroRedoubts()
    { return true; }

// virtually every creature of darkness is represented; the many caverns
// unclaimed by intelligent races are the domains of slimes, oozes, jellies,
// animated fungi, scavengers and all the other unintelligent creatures that
// prowl the Underdark in search of prey.
inline bool dnapDarkDomains()
    { return true; }

// a hundred or more denizens of the Plane of Earth cluster near the center of
// the Dark Realms, where their escape route is always near.
inline int dnapEarthDenizens()
    { return 100; }

// earth elementals are the most numerous of the cluster, but xorn, crysmal,
// galeb duhr, chaggrin and dao may also be encountered; the earth creatures
// unite to defend against any threat to the vortex leading to their plane.
inline bool dnapEarthRoster()
    { return true; }

// the air in the Dark Realms is generally stale and foul-smelling; the water
// supply is sufficient to keep the air humid and provide drinking water for
// creatures not particular about quality, but could not support a community
// of more humanoid inhabitants.
inline bool dnapStaleAir()
    { return true; }

// there is a great deal of mineral wealth here, nearly all of it unexploited;
// the areas around the vortex have been thoroughly scavenged by the Plane of
// Earth creatures (particularly the crysmal), but the rest offers a wide
// variety of gems and precious metals for the intrepid miner - the deadly
// hazards forestall almost any mining operation, however.
inline bool dnapUnminedWealth()
    { return true; }

// a creature flying over the center of the mud lake can see the mud spinning
// deliberately, like a watery whirlpool in slow motion: an elemental vortex
// to the Plane of Earth, very similar to the Area 21 Plane of Fire
// connection, with mud seeping through at just the pace matching the inflow.
inline bool dnapMudWhirlpool()
    { return true; }

// moving from the Prime Plane to the Plane of Earth requires the same
// procedure as the Area 21 journey to the Plane of Fire; travelers take no
// heat damage but must hold their breath or carry breathable air for the time
// spent in transit.
inline bool dnapEarthJourney()
    { return true; }

}   // namespace rules
