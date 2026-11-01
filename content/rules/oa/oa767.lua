-- oa767: promoted from rules/oa138buildings.h (the OA DAILY LIFE - BUILDINGS, printed capture pp. 308-309 (with the food tail);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 767,
  "prefix" = "oa767",
  "banner" = {
      "title" = "OA DAILY LIFE - BUILDINGS, printed capture pp. 308-309 (with the food tail",
      "provenance" = "of p. 308) - the three building types of Kara-Tur census 689 -> 690.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 220 closed, 15 open - the Buildings box flips (census 689 -> 690); NEXT - R768: Manners (capture p. 312), prefix dmd (verify free at the landing), audit \"R768 OA Daily Life Manners audit\", include after rules/oa138buildings.h",
    },
  "consts" = { {
      "name" = "dmcTownMealsCount",
      "value" = 4,
      "comment" = "the town meals count - a typical town day holds four meals: the morning buns and gruel, the largest mid-day meal, the late-day tea and candies, and the light evening meal (print capture p. 308)",
    }, {
      "name" = "dmcFishMainMeatSource",
      "value" = 1,
      "comment" = "the fish main meat source - fish the main source of meat, chicken and pork most common, game eaten when available, beef seldom as cattle are rare and specially regarded, barbarians eating mutton and horsemeat at feasts (print capture p. 308)",
    }, {
      "name" = "dmcTeaMostCommonDrink",
      "value" = 1,
      "comment" = "the tea most common drink - tea clearly the most common drink in many varieties, most drinking it plain, the nomads mixing it with milk and sugar and even serving it as a soup (print capture p. 308)",
    }, {
      "name" = "dmcRiceWinesHeated",
      "value" = 1,
      "comment" = "the rice wines heated - rice wines (sake and the like) served heated in small cups, beers also made and drunk with meals (print capture p. 308)",
    }, {
      "name" = "dmcSteppeMilkDrinks",
      "value" = 1,
      "comment" = "the steppe milk drinks - the steppes drink of fermented mare milk, a claimed refreshing tonic, mixed with mare blood on special occasions for warriors before or after battle, milk rare elsewhere (print capture p. 308)",
    }, {
      "name" = "dmcTownMeals",
      "value" = 1,
      "comment" = "the town meals - in town the morning meal of steamed buns, dumplings, rice or gruel, and pickles; the mid-day meal the largest with rice, vegetables, fish or chicken, pickles, and tea; the late-day tea and rice candies or sweet buns; the light evening meal of rice and a few simple delicacies (print capture p. 308)",
    }, {
      "name" = "dmcTravelMeals",
      "value" = 1,
      "comment" = "the travel meals - when traveling the morning meal of gruel, rice, millet, or barley before breaking camp; the midway ricecake, cold rice, or leaf-wrapped packet with fruit if available; the evening rice with dried fish and vegetables, fresh game if the hunt went well (print capture p. 308)",
    }, {
      "name" = "dmcBuildingTypesCount",
      "value" = 3,
      "comment" = "the building types count - three main building types in Kara-Tur: the homes of commoners, the palaces of the wealthy and powerful, and temples, each with distinctive methods and materials, several floorplans provided for the DM (print capture pp. 308-309)",
    }, {
      "name" = "dmcPeasantWoodHouse",
      "value" = 1,
      "comment" = "the peasant wood house - peasant homes of wood or clay brick, the simplest a single large room with a bare-earth floor, the thick thatch roof steeply angled to shed snow and water, the broad eaves shading sun and winter snow (print capture pp. 308-309)",
    }, {
      "name" = "dmcWindowsCoverings",
      "value" = 1,
      "comment" = "the windows coverings - windows built into the walls for light, covered with a simple wood lattice, removable shutters, bamboo shades, or glazed paper (print capture pp. 308-309)",
    }, {
      "name" = "dmcVerandaHearth",
      "value" = 1,
      "comment" = "the veranda hearth - the small veranda, a raised deck as wide as the eaves covered with woven straw mats; the central room dominated by the earthen hearth, a stone-lined pit with a hook for cooking pots, the smoke hole in the roof; with no central heating the family life centers around the hearth (print capture pp. 308-309)",
    }, {
      "name" = "dmcRaisedPlatforms",
      "value" = 1,
      "comment" = "the raised platforms - the house sometimes divided by raised wooden platforms for sleeping and other activities, separated by removable paper screens or permanent wooden walls, storage in the walls and under the platforms, the attic reached by a broad-stepped ladder (print capture pp. 308-309)",
    }, {
      "name" = "dmcTileRoofStatus",
      "value" = 1,
      "comment" = "the tile roof status - the thatch roof requires regular care; in wealthier homes replaced by glazed tile, durable and a sign of the status of the homeowner, the ridge and eaves decorated with wooden forms and carvings (print capture pp. 308-309)",
    }, {
      "name" = "dmcCityPackedHouses",
      "value" = 1,
      "comment" = "the city packed houses - in cities and large towns houses tightly packed on narrow twisting streets, mostly tile-roofed with thatch the sign of a truly poor man (print capture pp. 308-309)",
    }, {
      "name" = "dmcShopsInHomes",
      "value" = 1,
      "comment" = "the shops in homes - most shops and businesses in the same building as the family home, the large front shutters opened to form a table for goods; the common courtyard with a well behind the row; larger wealthier homes set off by walled gardens or a central courtyard square; houses seldom more than one story high (print capture pp. 308-309)",
    }, {
      "name" = "dmcOutbuildingsGranaries",
      "value" = 1,
      "comment" = "the outbuildings granaries - the family workshops, stables, and granaries built in a similar style to the main house, granaries almost always of plaster and stone due to the great risk of fire - the rice wealth could never be replaced (print capture pp. 308-309)",
    }, {
      "name" = "dmcFireTeamsPrimitive",
      "value" = 1,
      "comment" = "the fire teams primitive - wood, thatch, and paper buildings very susceptible to fire, building fires greatly feared in large cities where winds carry sparks through entire sections; every ward with organized fire-fighter teams under a noble, the practices primitive - bucket gangs and pulling down nearby buildings (print capture pp. 308-309)",
    }, {
      "name" = "dmcClayBrickHouses",
      "value" = 1,
      "comment" = "the clay brick houses - pressed clay brick homes where wood is scarce, normally two stories around a courtyard or walled garden, the clay stove kitchen, charcoal braziers in cold weather, flat roofs used as decks or glazed tile, red-painted ornaments (red lucky), far less susceptible to fire (print capture pp. 308-309)",
    }, {
      "name" = "dmcNobleHouses",
      "value" = 1,
      "comment" = "the noble houses - identical to their peasant counterparts except larger and more lavish, extensive landscaped gardens with a man-made pond or stream, always surrounded by walls for privacy and protection from wars and revolts, solid wooden floors and movable screens (print capture pp. 308-309)",
    }, {
      "name" = "dmcTempleCompounds",
      "value" = 1,
      "comment" = "the temple compounds - temple buildings quite lavish, a group of buildings within a single walled compound, wood with magnificent stone pagodas, the raised foundation and stone terraces, the broad veranda under the tiled eaves, the main hall with its imposing statue of the deity, the priests chambers, the landscaped grounds (print capture pp. 308-309)",
    }, {
      "name" = "dmcMilitaryCastles",
      "value" = 1,
      "comment" = "the military castles - the special class of military buildings, castles and watchtowers with many similarities to the west, located on the commanding point, the many-story keep of heavy stone the last defense, reached by ramps and staircases, the lesser towers and walls with few gates and loopholes, the surrounding ditches and moats - sieging a castle a formidable undertaking (print capture pp. 308-309)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dmcBuildingTypesCount']() != 3  or m['dmcTownMealsCount']() != 4  or  m['dmcFishMainMeatSource']() != 1  or  m['dmcTeaMostCommonDrink']() != 1  or  m['dmcRiceWinesHeated']() != 1  or  m['dmcSteppeMilkDrinks']() != 1  or  m['dmcTownMeals']() != 1  or  m['dmcTravelMeals']() != 1  or  m['dmcPeasantWoodHouse']() != 1  or  m['dmcWindowsCoverings']() != 1  or  m['dmcVerandaHearth']() != 1  or  m['dmcRaisedPlatforms']() != 1  or  m['dmcTileRoofStatus']() != 1  or  m['dmcCityPackedHouses']() != 1  or  m['dmcShopsInHomes']() != 1  or  m['dmcOutbuildingsGranaries']() != 1  or  m['dmcFireTeamsPrimitive']() != 1  or  m['dmcClayBrickHouses']() != 1  or  m['dmcNobleHouses']() != 1  or  m['dmcTempleCompounds']() != 1  or  m['dmcMilitaryCastles']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dmcFishMainMeatSource']() != 1  or m['dmcTeaMostCommonDrink']() != 1",
      "note" = "the meat example",
    }, {
      "expr" = "m['dmcRiceWinesHeated']() != 1  or m['dmcSteppeMilkDrinks']() != 1",
      "note" = "the drinks example",
    }, {
      "expr" = "m['dmcTownMealsCount']() != 4  or m['dmcTownMeals']() != 1  or m['dmcTravelMeals']() != 1",
      "note" = "the meals example",
    }, {
      "expr" = "m['dmcBuildingTypesCount']() != 3  or m['dmcPeasantWoodHouse']() != 1  or m['dmcWindowsCoverings']() != 1",
      "note" = "the wood house example",
    }, {
      "expr" = "m['dmcVerandaHearth']() != 1  or m['dmcRaisedPlatforms']() != 1",
      "note" = "the hearth example",
    }, {
      "expr" = "m['dmcTileRoofStatus']() != 1  or m['dmcCityPackedHouses']() != 1",
      "note" = "the tile example",
    }, {
      "expr" = "m['dmcShopsInHomes']() != 1  or m['dmcOutbuildingsGranaries']() != 1",
      "note" = "the street example",
    }, {
      "expr" = "m['dmcFireTeamsPrimitive']() != 1",
      "note" = "the fire example",
    }, {
      "expr" = "m['dmcClayBrickHouses']() != 1  or m['dmcNobleHouses']() != 1",
      "note" = "the brick example",
    }, {
      "expr" = "m['dmcTempleCompounds']() != 1  or m['dmcMilitaryCastles']() != 1",
      "note" = "the compound example",
    } },
  "audit" = {
      "label" = "R767 OA Daily Life Buildings audit",
      "comment" = "OA round one hundred fifty-four (capture pp. 308-309, with the food tail of p. 308 folded in): Buildings - the fish and tea tail of Food, the peasant wood house, the city packing and fire teams, the clay brick and noble houses, the temple compounds, the military castles, single-pass pins per the R679 provenance shift",
    },
}
