-- oa766: promoted from rules/oa/oa137food.h (the OA DAILY LIFE - FOOD, printed capture p. 307 - the rice constant and the);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 766,
  "prefix" = "oa766",
  "banner" = {
      "title" = "OA DAILY LIFE - FOOD, printed capture p. 307 - the rice constant and the",
      "provenance" = "food of Kara-Tur census 688 -> 689.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 219 closed, 16 open - the Food box flips (census 688 -> 689); NEXT - R767: Buildings (capture pp. 308-312), prefix dmc (verify free at the landing), audit \"R767 OA Daily Life Buildings audit\", include after rules/oa/oa137food.h",
    },
  "consts" = { {
      "name" = "dmbRiceUsesCount",
      "value" = 7,
      "comment" = "the rice uses count - rice used in a multitude of ways: boiled main course, gruel, leftovers mixed with meats and vegetables, vinegared and served cold, pounded into rice-cakes, ground into flour for buns or noodles, mashed and fermented into sake, seven uses (print capture p. 307)",
    }, {
      "name" = "dmbRiceTheConstant",
      "value" = 1,
      "comment" = "the rice constant - rice the one constant throughout the civilized lands of Kara-Tur, everyone eats rice and it is served with virtually every meal (print capture p. 307)",
    }, {
      "name" = "dmbEatenRiceGreeting",
      "value" = 1,
      "comment" = "the eaten rice greeting - in Shou Lung and Tu Lung people greet each other not with the friendly Hello of the west but with Have you eaten rice today (print capture p. 307)",
    }, {
      "name" = "dmbRiceStuffOfLife",
      "value" = 1,
      "comment" = "the rice stuff of life - like wheat in the west, rice is the stuff of life in Kara-Tur (print capture p. 307)",
    }, {
      "name" = "dmbPoorMansSubstitutes",
      "value" = 1,
      "comment" = "the poor man substitutes - when rice is unavailable or too valuable, yellow millet, sorghum, or barley substituted, the poor man food, pounded into cakes or cooked into a thick gruel (print capture p. 307)",
    }, {
      "name" = "dmbBeanVarietiesCount",
      "value" = 4,
      "comment" = "the bean varieties count - soybeans, red beans, black beans, and brown beans, four varieties (print capture p. 307)",
    }, {
      "name" = "dmbBeansWithRice",
      "value" = 1,
      "comment" = "the beans with rice - beans used in addition to or in place of rice, stewed or mashed into a paste (print capture p. 307)",
    }, {
      "name" = "dmbBeanPasteVariety",
      "value" = 1,
      "comment" = "the bean paste variety - the paste fermented, flavored, dried, or sweetened, used as a dip, stuffed into buns, formed into candies, or used as a sauce (print capture p. 307)",
    }, {
      "name" = "dmbSoyPreparedFoods",
      "value" = 1,
      "comment" = "the soy prepared foods - from soybeans come the unusual prepared foods soy sauce and tofu (print capture p. 307)",
    }, {
      "name" = "dmbTofuFromSoyMilk",
      "value" = 1,
      "comment" = "the tofu from soy milk - tofu prepared from the juice or milk of mashed soybeans, curdled and pressed into semi-soft cakes, stewed, dried, or deep-fried (print capture p. 307)",
    }, {
      "name" = "dmbSoySauceProcess",
      "value" = 1,
      "comment" = "the soy sauce process - soy sauce prepared through mashing, fermenting, soaking, and rinsing, a thin salty sauce used as a flavoring for nearly anything (print capture p. 307)",
    }, {
      "name" = "dmbVegetablesNextToRice",
      "value" = 1,
      "comment" = "the vegetables next to rice - next to rice in importance come vegetables of many types and flavors, grown in family garden plots, stewed, fried, pickled, and steamed (print capture p. 307)",
    }, {
      "name" = "dmbVegetablesRarelyRaw",
      "value" = 1,
      "comment" = "the vegetables rarely raw - they are almost never eaten raw except as garnishes (print capture p. 307)",
    }, {
      "name" = "dmbGardenVariety",
      "value" = 1,
      "comment" = "the garden variety - along with the vegetables an assortment of fruits, nuts, grasses, and flowers, from bamboo shoots and water chestnut roots to persimmons, lychees, and many others (print capture p. 307)",
    }, {
      "name" = "dmbPickledPreparations",
      "value" = 1,
      "comment" = "the pickled preparations - pickled greens or radishes often with chilies, pickled plums with virtually anything pickled, dried flower buds, dried chestnuts, and pastes (print capture p. 307)",
    }, {
      "name" = "dmbWaterProductsImportant",
      "value" = 1,
      "comment" = "the water products important - the products of the water important to the Oriental diet, consumed only by those living near the sea, a river, or lake (print capture p. 307)",
    }, {
      "name" = "dmbFishHundredsOfVarieties",
      "value" = 1,
      "comment" = "the fish hundreds of varieties - hundreds of varieties of fish eaten, taken fresh from the water, from the commonplace to the exotic (print capture p. 307)",
    }, {
      "name" = "dmbDelicaciesAndDangers",
      "value" = 1,
      "comment" = "the delicacies and dangers - the desired delicacies include the pufferfish (deadly poisonous if incorrectly prepared), sea cucumber, jellyfish, octopus, eels, shrimp, and fish maw (print capture p. 307)",
    }, {
      "name" = "dmbKelpHarvested",
      "value" = 1,
      "comment" = "the kelp harvested - various types of kelp harvested from the ocean to be dried and used in soups and as flavorings (print capture p. 307)",
    }, {
      "name" = "dmbSeaFullyUsed",
      "value" = 1,
      "comment" = "the sea fully used - virtually anything that comes from the sea is used in some way (print capture p. 307)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dmbRiceUsesCount']() != 7  or m['dmbBeanVarietiesCount']() != 4  or  m['dmbRiceTheConstant']() != 1  or  m['dmbEatenRiceGreeting']() != 1  or  m['dmbRiceStuffOfLife']() != 1  or  m['dmbPoorMansSubstitutes']() != 1  or  m['dmbBeansWithRice']() != 1  or  m['dmbBeanPasteVariety']() != 1  or  m['dmbSoyPreparedFoods']() != 1  or  m['dmbTofuFromSoyMilk']() != 1  or  m['dmbSoySauceProcess']() != 1  or  m['dmbVegetablesNextToRice']() != 1  or  m['dmbVegetablesRarelyRaw']() != 1  or  m['dmbGardenVariety']() != 1  or  m['dmbPickledPreparations']() != 1  or  m['dmbWaterProductsImportant']() != 1  or  m['dmbFishHundredsOfVarieties']() != 1  or  m['dmbDelicaciesAndDangers']() != 1  or  m['dmbKelpHarvested']() != 1  or  m['dmbSeaFullyUsed']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dmbRiceUsesCount']() != 7  or m['dmbRiceTheConstant']() != 1  or m['dmbEatenRiceGreeting']() != 1",
      "note" = "the rice example",
    }, {
      "expr" = "m['dmbRiceStuffOfLife']() != 1  or m['dmbPoorMansSubstitutes']() != 1",
      "note" = "the life example",
    }, {
      "expr" = "m['dmbBeanVarietiesCount']() != 4  or m['dmbBeansWithRice']() != 1  or m['dmbBeanPasteVariety']() != 1",
      "note" = "the beans example",
    }, {
      "expr" = "m['dmbSoyPreparedFoods']() != 1  or m['dmbTofuFromSoyMilk']() != 1  or m['dmbSoySauceProcess']() != 1",
      "note" = "the soy example",
    }, {
      "expr" = "m['dmbVegetablesNextToRice']() != 1  or m['dmbVegetablesRarelyRaw']() != 1  or m['dmbGardenVariety']() != 1",
      "note" = "the garden example",
    }, {
      "expr" = "m['dmbPickledPreparations']() != 1",
      "note" = "the pickles example",
    }, {
      "expr" = "m['dmbWaterProductsImportant']() != 1  or m['dmbFishHundredsOfVarieties']() != 1  or m['dmbDelicaciesAndDangers']() != 1",
      "note" = "the water example",
    }, {
      "expr" = "m['dmbKelpHarvested']() != 1  or m['dmbSeaFullyUsed']() != 1",
      "note" = "the sea example",
    } },
  "audit" = {
      "label" = "R766 OA Daily Life Food audit",
      "comment" = "OA round one hundred fifty-three (capture p. 307): the Chapter 15 daily-life opener, Food - the rice constant, the eaten-rice greeting, the poor man millet, the soy sauce and tofu, the garden vegetables, the water products, single-pass pins per the R679 provenance shift",
    },
}
