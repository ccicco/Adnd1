// =========================================================================================
// Adnd1 - rules/oa138buildings.h
// OA DAILY LIFE - BUILDINGS, printed capture pp. 308-309 (with the food tail
// of p. 308) - the three building types of Kara-Tur
// census 689 -> 690.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 220 closed, 15 open - the Buildings box
// flips (census 689 -> 690); NEXT - R768: Manners (capture p. 312), prefix
// dmd (verify free at the landing), audit "R768 OA Daily Life Manners audit",
// include after rules/oa138buildings.h
//
namespace rules {

// ---- the food tail ----

// the town meals count - a typical town day holds four meals: the morning
// buns and gruel, the largest mid-day meal, the late-day tea and candies, and
// the light evening meal (print capture p. 308)
inline int dmcTownMealsCount()
    { return 4; }

// the fish main meat source - fish the main source of meat, chicken and pork
// most common, game eaten when available, beef seldom as cattle are rare and
// specially regarded, barbarians eating mutton and horsemeat at feasts (print
// capture p. 308)
inline int dmcFishMainMeatSource()
    { return 1; }

// the tea most common drink - tea clearly the most common drink in many
// varieties, most drinking it plain, the nomads mixing it with milk and sugar
// and even serving it as a soup (print capture p. 308)
inline int dmcTeaMostCommonDrink()
    { return 1; }

// the rice wines heated - rice wines (sake and the like) served heated in
// small cups, beers also made and drunk with meals (print capture p. 308)
inline int dmcRiceWinesHeated()
    { return 1; }

// the steppe milk drinks - the steppes drink of fermented mare milk, a
// claimed refreshing tonic, mixed with mare blood on special occasions for
// warriors before or after battle, milk rare elsewhere (print capture p. 308)
inline int dmcSteppeMilkDrinks()
    { return 1; }

// the town meals - in town the morning meal of steamed buns, dumplings, rice
// or gruel, and pickles; the mid-day meal the largest with rice, vegetables,
// fish or chicken, pickles, and tea; the late-day tea and rice candies or
// sweet buns; the light evening meal of rice and a few simple delicacies
// (print capture p. 308)
inline int dmcTownMeals()
    { return 1; }

// the travel meals - when traveling the morning meal of gruel, rice, millet,
// or barley before breaking camp; the midway ricecake, cold rice, or
// leaf-wrapped packet with fruit if available; the evening rice with dried
// fish and vegetables, fresh game if the hunt went well (print capture p.
// 308)
inline int dmcTravelMeals()
    { return 1; }

// ---- the peasant homes ----

// the building types count - three main building types in Kara-Tur: the homes
// of commoners, the palaces of the wealthy and powerful, and temples, each
// with distinctive methods and materials, several floorplans provided for the
// DM (print capture pp. 308-309)
inline int dmcBuildingTypesCount()
    { return 3; }

// the peasant wood house - peasant homes of wood or clay brick, the simplest
// a single large room with a bare-earth floor, the thick thatch roof steeply
// angled to shed snow and water, the broad eaves shading sun and winter snow
// (print capture pp. 308-309)
inline int dmcPeasantWoodHouse()
    { return 1; }

// the windows coverings - windows built into the walls for light, covered
// with a simple wood lattice, removable shutters, bamboo shades, or glazed
// paper (print capture pp. 308-309)
inline int dmcWindowsCoverings()
    { return 1; }

// the veranda hearth - the small veranda, a raised deck as wide as the eaves
// covered with woven straw mats; the central room dominated by the earthen
// hearth, a stone-lined pit with a hook for cooking pots, the smoke hole in
// the roof; with no central heating the family life centers around the hearth
// (print capture pp. 308-309)
inline int dmcVerandaHearth()
    { return 1; }

// the raised platforms - the house sometimes divided by raised wooden
// platforms for sleeping and other activities, separated by removable paper
// screens or permanent wooden walls, storage in the walls and under the
// platforms, the attic reached by a broad-stepped ladder (print capture pp.
// 308-309)
inline int dmcRaisedPlatforms()
    { return 1; }

// ---- the towns and fire ----

// the tile roof status - the thatch roof requires regular care; in wealthier
// homes replaced by glazed tile, durable and a sign of the status of the
// homeowner, the ridge and eaves decorated with wooden forms and carvings
// (print capture pp. 308-309)
inline int dmcTileRoofStatus()
    { return 1; }

// the city packed houses - in cities and large towns houses tightly packed on
// narrow twisting streets, mostly tile-roofed with thatch the sign of a truly
// poor man (print capture pp. 308-309)
inline int dmcCityPackedHouses()
    { return 1; }

// the shops in homes - most shops and businesses in the same building as the
// family home, the large front shutters opened to form a table for goods; the
// common courtyard with a well behind the row; larger wealthier homes set off
// by walled gardens or a central courtyard square; houses seldom more than
// one story high (print capture pp. 308-309)
inline int dmcShopsInHomes()
    { return 1; }

// the outbuildings granaries - the family workshops, stables, and granaries
// built in a similar style to the main house, granaries almost always of
// plaster and stone due to the great risk of fire - the rice wealth could
// never be replaced (print capture pp. 308-309)
inline int dmcOutbuildingsGranaries()
    { return 1; }

// the fire teams primitive - wood, thatch, and paper buildings very
// susceptible to fire, building fires greatly feared in large cities where
// winds carry sparks through entire sections; every ward with organized
// fire-fighter teams under a noble, the practices primitive - bucket gangs
// and pulling down nearby buildings (print capture pp. 308-309)
inline int dmcFireTeamsPrimitive()
    { return 1; }

// ---- the brick and noble homes ----

// the clay brick houses - pressed clay brick homes where wood is scarce,
// normally two stories around a courtyard or walled garden, the clay stove
// kitchen, charcoal braziers in cold weather, flat roofs used as decks or
// glazed tile, red-painted ornaments (red lucky), far less susceptible to
// fire (print capture pp. 308-309)
inline int dmcClayBrickHouses()
    { return 1; }

// the noble houses - identical to their peasant counterparts except larger
// and more lavish, extensive landscaped gardens with a man-made pond or
// stream, always surrounded by walls for privacy and protection from wars and
// revolts, solid wooden floors and movable screens (print capture pp.
// 308-309)
inline int dmcNobleHouses()
    { return 1; }

// ---- the temples and castles ----

// the temple compounds - temple buildings quite lavish, a group of buildings
// within a single walled compound, wood with magnificent stone pagodas, the
// raised foundation and stone terraces, the broad veranda under the tiled
// eaves, the main hall with its imposing statue of the deity, the priests
// chambers, the landscaped grounds (print capture pp. 308-309)
inline int dmcTempleCompounds()
    { return 1; }

// the military castles - the special class of military buildings, castles and
// watchtowers with many similarities to the west, located on the commanding
// point, the many-story keep of heavy stone the last defense, reached by
// ramps and staircases, the lesser towers and walls with few gates and
// loopholes, the surrounding ditches and moats - sieging a castle a
// formidable undertaking (print capture pp. 308-309)
inline int dmcMilitaryCastles()
    { return 1; }

}   // namespace rules
