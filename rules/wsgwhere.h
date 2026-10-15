// =========================================================================================
// Adnd1 - rules/wsgwhere.h
// R468: the WSG WHERE WATER IS FOUND slice - the standing-water basis (the
// table chance models a sizable quantity of standing water, not large enough
// for a lake or pond: an uncharted pool, a small depression or basin holding
// rainstorm water not yet evaporated or absorbed), the drought reduction (no
// rain for several days lets the DM cut the find chance: a flat plain
// completely dried out, a swamp keeping standing water practically all the
// time), the water table (the level beneath the ground at which water lies
// after soaking into the terrain: a foot or two in low elevation, possibly
// higher than the terrain in a swamp near sea level, dozens or hundreds of
// feet in high elevation without a large fresh-water body, greatly varying in
// a desert), the non-absorbent exception (rocky mountains, frozen ground),
// the dig-for-water chance (DM-determined by terrain and elevation, the
// desert exception) and vegetation as a water source (the subtropical and
// tropical water-storing plants, the cactus, the drought plains and hills,
// the DM availability and quantity ruling), printed p. 59 with the
// water-table material on p. 60.
// census 392 -> 393.
//
// Ground truth two-way, pure prose: the user-run tesseract text of printed p.
// 59 (the --psm 4 run from the R467 extraction) vs the djvu word layer
// (Guide_0059 tail and Guide_0060). The two readers agree on every mechanic
// and every number. The section heading sits at the bottom of the printed p.
// 59 right column; the prose continues onto printed p. 60, ending at the
// WATER IN THE DESERT heading. The permafrost discussion (printed p. 60,
// referenced by the frozen-ground exception in the water-table paragraph) is
// deferred to the next round with the desert material. The bad-water warning
// (the vegetation-free waterhole with skeletal remains) belongs to the
// tainted-water text and stays unpinned this round.
//
// No printed grid in this slice - the standing-water basis, the drought
// reduction, the water-table depth rules and the vegetation source pin as
// consts and bools, every one audit-verified against the model.
//
namespace rules {

// ---- The standing-water basis ----

// the Table 34 chance models a sizable quantity of standing water - not large
// enough to qualify as a lake or pond: an uncharted pool, or a small
// depression or basin holding rainstorm water not yet evaporated or absorbed
inline bool wwfStandingWaterBasis()
    { return true; }

// if no rain has fallen for several days, the DM may reduce the chance of
// finding standing water in certain terrains
inline bool wwfDroughtDMReduction()
    { return true; }

// a flat plain may be completely dried out after a few days without
// precipitation
inline bool wwfFlatPlainDriesOut()
    { return true; }

// a swampy area will have standing water practically all the time regardless
// of how long since the last rain
inline bool wwfSwampAlwaysStanding()
    { return true; }

// ---- The water table ----

// the water table is the level beneath the ground at which water lies after
// soaking into the terrain - not the Chance of Finding Water Table
inline bool wwfTableIsUndergroundLevel()
    { return true; }

// in an area of low elevation the water table may be only a foot or two
// beneath the ground: the minimum depth in feet
inline int wwfLowElevMinFt()
    { return 1; }

// the low-elevation water-table depth: the maximum in feet (a foot or two)
inline int wwfLowElevMaxFt()
    { return 2; }

// in a swamp, where elevation is close to sea level, the water table may
// actually be higher than the terrain
inline bool wwfSwampTableAboveTerrain()
    { return true; }

// in high elevation with no large body of fresh water the water table may be
// dozens of feet beneath the surface: the dozens floor (2d12, 24 feet, the
// model floor)
inline int wwfHighElevMinFt()
    { return 24; }

// the high-elevation water table may be dozens or even hundreds of feet
// beneath the surface: the hundreds floor (100 feet)
inline int wwfHighElevMaxFt()
    { return 100; }

// in the almost moisture-free desert environment the location of the water
// table varies greatly (the desert exception, detailed in its own section)
inline bool wwfDesertTableVaries()
    { return true; }

// the water table is nonexistent where the terrain is not absorbent: a rocky
// mountain range with little or no loose soil, or frozen ground
inline bool wwfTableNonexistentNonabsorbent()
    { return true; }

// ---- Digging for underground water ----

// characters who fail to locate surface water on terrain where underground
// water may exist can be allowed a chance to find water by digging down a
// certain distance
inline bool wwfDigChanceAfterSurfaceFail()
    { return true; }

// whether underground water exists and how far down it lies are DM
// determinations based on the terrain and elevation; deserts are the
// exception with their own rules
inline bool wwfDigDepthDMRuling()
    { return true; }

// ---- Vegetation as a water source ----

// vegetation is another natural source of water, particularly in hot climates
// where many plants store fresh water inside their stems or branches as a
// safeguard against a dry spell
inline bool wwfVegetationWaterSource()
    { return true; }

// the cactus plant ability to store water inside itself has kept many desert
// travelers from dying of thirst
inline bool wwfCactusStoresWater()
    { return true; }

// other water-storing plants not necessarily found in the desert may keep
// adventurers fortified on plains or in hilly areas during a drought
inline bool wwfDroughtPlantsOnPlainsHills()
    { return true; }

// the DM decides whether water-bearing plants are readily available and how
// much water they provide
inline bool wwfPlantQuantityDMRuling()
    { return true; }

}   // namespace rules
