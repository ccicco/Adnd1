// =========================================================================================
// Adnd1 - rules/oa137food.h
// OA DAILY LIFE - FOOD, printed capture p. 307 - the rice constant and the
// food of Kara-Tur
// census 688 -> 689.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 219 closed, 16 open - the Food box flips
// (census 688 -> 689); NEXT - R767: Buildings (capture pp. 308-312), prefix
// dmc (verify free at the landing), audit "R767 OA Daily Life Buildings
// audit", include after rules/oa137food.h
//
namespace rules {

// ---- the rice constant ----

// the rice uses count - rice used in a multitude of ways: boiled main course,
// gruel, leftovers mixed with meats and vegetables, vinegared and served
// cold, pounded into rice-cakes, ground into flour for buns or noodles,
// mashed and fermented into sake, seven uses (print capture p. 307)
inline int dmbRiceUsesCount()
    { return 7; }

// the rice constant - rice the one constant throughout the civilized lands of
// Kara-Tur, everyone eats rice and it is served with virtually every meal
// (print capture p. 307)
inline int dmbRiceTheConstant()
    { return 1; }

// the eaten rice greeting - in Shou Lung and Tu Lung people greet each other
// not with the friendly Hello of the west but with Have you eaten rice today
// (print capture p. 307)
inline int dmbEatenRiceGreeting()
    { return 1; }

// the rice stuff of life - like wheat in the west, rice is the stuff of life
// in Kara-Tur (print capture p. 307)
inline int dmbRiceStuffOfLife()
    { return 1; }

// ---- the poor man food ----

// the poor man substitutes - when rice is unavailable or too valuable, yellow
// millet, sorghum, or barley substituted, the poor man food, pounded into
// cakes or cooked into a thick gruel (print capture p. 307)
inline int dmbPoorMansSubstitutes()
    { return 1; }

// the bean varieties count - soybeans, red beans, black beans, and brown
// beans, four varieties (print capture p. 307)
inline int dmbBeanVarietiesCount()
    { return 4; }

// the beans with rice - beans used in addition to or in place of rice, stewed
// or mashed into a paste (print capture p. 307)
inline int dmbBeansWithRice()
    { return 1; }

// the bean paste variety - the paste fermented, flavored, dried, or
// sweetened, used as a dip, stuffed into buns, formed into candies, or used
// as a sauce (print capture p. 307)
inline int dmbBeanPasteVariety()
    { return 1; }

// ---- the soy preparations ----

// the soy prepared foods - from soybeans come the unusual prepared foods soy
// sauce and tofu (print capture p. 307)
inline int dmbSoyPreparedFoods()
    { return 1; }

// the tofu from soy milk - tofu prepared from the juice or milk of mashed
// soybeans, curdled and pressed into semi-soft cakes, stewed, dried, or
// deep-fried (print capture p. 307)
inline int dmbTofuFromSoyMilk()
    { return 1; }

// the soy sauce process - soy sauce prepared through mashing, fermenting,
// soaking, and rinsing, a thin salty sauce used as a flavoring for nearly
// anything (print capture p. 307)
inline int dmbSoySauceProcess()
    { return 1; }

// ---- the garden ----

// the vegetables next to rice - next to rice in importance come vegetables of
// many types and flavors, grown in family garden plots, stewed, fried,
// pickled, and steamed (print capture p. 307)
inline int dmbVegetablesNextToRice()
    { return 1; }

// the vegetables rarely raw - they are almost never eaten raw except as
// garnishes (print capture p. 307)
inline int dmbVegetablesRarelyRaw()
    { return 1; }

// the garden variety - along with the vegetables an assortment of fruits,
// nuts, grasses, and flowers, from bamboo shoots and water chestnut roots to
// persimmons, lychees, and many others (print capture p. 307)
inline int dmbGardenVariety()
    { return 1; }

// the pickled preparations - pickled greens or radishes often with chilies,
// pickled plums with virtually anything pickled, dried flower buds, dried
// chestnuts, and pastes (print capture p. 307)
inline int dmbPickledPreparations()
    { return 1; }

// ---- the water products ----

// the water products important - the products of the water important to the
// Oriental diet, consumed only by those living near the sea, a river, or lake
// (print capture p. 307)
inline int dmbWaterProductsImportant()
    { return 1; }

// the fish hundreds of varieties - hundreds of varieties of fish eaten, taken
// fresh from the water, from the commonplace to the exotic (print capture p.
// 307)
inline int dmbFishHundredsOfVarieties()
    { return 1; }

// the delicacies and dangers - the desired delicacies include the pufferfish
// (deadly poisonous if incorrectly prepared), sea cucumber, jellyfish,
// octopus, eels, shrimp, and fish maw (print capture p. 307)
inline int dmbDelicaciesAndDangers()
    { return 1; }

// the kelp harvested - various types of kelp harvested from the ocean to be
// dried and used in soups and as flavorings (print capture p. 307)
inline int dmbKelpHarvested()
    { return 1; }

// the sea fully used - virtually anything that comes from the sea is used in
// some way (print capture p. 307)
inline int dmbSeaFullyUsed()
    { return 1; }

}   // namespace rules
