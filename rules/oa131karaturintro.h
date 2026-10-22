// =========================================================================================
// Adnd1 - rules/oa131karaturintro.h
// OA SETTING - THE KARA-TUR OVERVIEW INTRO, GEOGRAPHY, AND POPULATION,
// printed capture pp. 301-303 - the setting chapter opens
// census 682 -> 683.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 213 closed, 22 open - the Population box
// flips (census 682 -> 683); NEXT - R761: Shou Lung (capture p. 303), prefix
// dlw (verify free at the landing), audit "R761 OA Shou Lung audit", include
// after rules/oa131karaturintro.h
//
namespace rules {

// ---- the chapter intro ----

// the main empire count - the four main empires of Kara-Tur, the Shou Lung,
// the Tu Lung, the Kozakura, and the Wa (print capture p. 301)
inline int dlvMainEmpireCount()
    { return 4; }

// the vast continental area - the tremendous range of climates, terrains,
// governments, societies, cultures, and beliefs, the general overview given
// as the beginning basis for an Oriental campaign (print capture p. 301)
inline int dlvVastContinentalArea()
    { return 1; }

// the Shou Lung empire - the first of the four main empires (print capture p.
// 301)
inline int dlvShouLungEmpire()
    { return 1; }

// the Tu Lung empire - the second of the four (print capture p. 301)
inline int dlvTuLungEmpire()
    { return 1; }

// the Kozakura empire - the third of the four (print capture p. 301)
inline int dlvKozakuraEmpire()
    { return 1; }

// the Wa empire - the fourth of the four (print capture p. 301)
inline int dlvWaEmpire()
    { return 1; }

// the surrounding political units - the uncivilized tribes, the tribal
// confederations, the warlord domains, the petty kingdoms, and the trading
// outposts, the alliances and the independents (print capture p. 301)
inline int dlvSurroundingUnits()
    { return 1; }

// the wilderness tracts - the unsettled and inhospitable lands of the hardy
// settlers, the bandits, the head-hunters, the non-human societies, and the
// monsters (print capture p. 301)
inline int dlvWildernessTracts()
    { return 1; }

// ---- the geography walk ----

// the terrain range - virtually every type of terrain commonly found in our
// world within the boundaries (print capture p. 302)
inline int dlvEveryTerrain()
    { return 1; }

// the Land of Snow Demons - the far northern permafrost tundra, the long
// harsh winters and the cool short summers (print capture p. 302)
inline int dlvLandOfSnowDemons()
    { return 1; }

// the northern woods - the thickly-wooded and swampy pine lands rich in
// wildlife south of the permafrost (print capture p. 302)
inline int dlvNorthernWoods()
    { return 1; }

// the Koryaz Mountains - the series of low mountain ranges of the rising
// south, the barrier of the Chukei Plateau (print capture p. 302)
inline int dlvKoryazMountains()
    { return 1; }

// the Ama Basin - the network of streams, lakes, and swamps feeding the Ama
// River, the raging spring torrent of the melting snow (print capture p. 302)
inline int dlvAmaBasin()
    { return 1; }

// the Celestial Sea - the sea the Ama drains into at its northern end (print
// capture p. 302)
inline int dlvCelestialSea()
    { return 1; }

// the Desert of Horses - the drier steppes beyond the foothills, the
// thousands of flat square miles variously known as the Beastlands (print
// capture p. 302)
inline int dlvDesertOfHorses()
    { return 1; }

// the northeast peninsula - the continent curving around the northern end of
// the Celestial Sea, the rugged islands of Wa and Kozakura breaking from its
// tip, the mild temperate climate of the warm currents (print capture p. 302)
inline int dlvNortheastPeninsula()
    { return 1; }

// the Chukei Plateau - the high plain of the northern provinces of Chukei and
// Pyint'sien, once fertile, now the dusty cold wind-swept plateau of the
// changed weather and the poor land management (print capture p. 302)
inline int dlvChukeiPlateau()
    { return 1; }

// the basin river count - the three major rivers of the basin, the Ch'ing
// Tung, the Hungsete, and the Fenghsintzu (print capture p. 302)
inline int dlvBasinRiverCount()
    { return 3; }

// the Three-River Basin - the main river basin of Kara-Tur, the fertile
// floodplains, the three rivers tumbling to the Celestial Sea, the warm
// temperate to sub-tropical weather (print capture p. 302)
inline int dlvThreeRiverBasin()
    { return 1; }

// the Peerless Mountains - the Wu Pi Te Shan Mo, the towering heights, the
// lush lower slopes and the jagged frozen peaks (print capture p. 302)
inline int dlvPeerlessMountains()
    { return 1; }

// the southern jungles - the volcanic chain and the fully tropical thick
// verdant jungles of the strange creatures, the feathery peninsulas of the
// Eastern Ocean (print capture p. 302)
inline int dlvSouthernJungles()
    { return 1; }

// ---- the population walk ----

// the population concentration - the majority within the Three-River Basin,
// its surrounding foothills, and the islands of Wa and Kozakura (print
// capture p. 302)
inline int dlvPopulationConcentration()
    { return 1; }

// the Shou Lung population - the empire centered in the basin and extending
// west and north, nearly all arable land farmed, the herding of the Chukei
// Plateau, the ores of the Peerless and Koryaz mountains (print capture p.
// 302)
inline int dlvShouLungPopulation()
    { return 1; }

// the Tu Lung population - the empire along the southern and southwestern
// basin, the farming of the Fenghsintzu banks, the lumbering of the southern
// hills (print capture p. 302)
inline int dlvTuLungPopulation()
    { return 1; }

// the Ama Basin nomads - the nomadic hunters of little farming, the elk and
// reindeer herds (print capture p. 302)
inline int dlvAmaNomads()
    { return 1; }

// the Snow Demon tribes - the few human tribes surviving on the seal, bear,
// and reindeer hunting (print capture p. 302)
inline int dlvSnowDemonTribes()
    { return 1; }

// the horse tribes - the nomadic horsemen of the Desert of Horses in a loose
// confederation, a strong leader recently welding them into a fierce
// warrior-nation (print capture p. 303)
inline int dlvHorseTribesConfederation()
    { return 1; }

// the petty kingdoms - the several on the lower peninsula, the tributary
// states of the Shou Lung Empire (print capture p. 303)
inline int dlvPettyKingdomsTributary()
    { return 1; }

// the primitive fishermen - the tribes on the islands between the peninsula
// and the islands of Wa and Kozakura (print capture p. 303)
inline int dlvPrimitiveFishermen()
    { return 1; }

// the island peoples - the Wa and Kozakura populated by a people different
// from the mainland, most likely an offshoot branch settled in ancient times
// (print capture p. 303)
inline int dlvIslandPeoples()
    { return 1; }

// the jungle tribes - the human population thinning south into the isolated
// tribes (print capture p. 303)
inline int dlvJungleTribes()
    { return 1; }

// the coastal states - the small states trading extensively with the north,
// paying tribute to Tu Lung or Shou Lung (print capture p. 303)
inline int dlvCoastalTributaryStates()
    { return 1; }

// the snake empire remnant - the ancient empire deep in the jungle that once
// held sway over the southern lands, ruled by a race of evil snake creatures
// possibly yuan-ti, the corrupted and transformed human groups (print capture
// p. 303)
inline int dlvSnakeEmpireRemnant()
    { return 1; }

}   // namespace rules
