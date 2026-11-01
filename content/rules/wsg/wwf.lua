-- wwf: promoted from tools/spec_r468.json (the R468: the WSG WHERE WATER IS FOUND slice - the standing-water basis (the table chance models a sizable quantity of standing water, not large enough for a lake or pond: an uncharted pool, a small depression or basin holding rainstorm water not yet evaporated or absorbed), the drought reduction (no rain for several days lets the DM cut the find chance: a flat plain completely dried out, a swamp keeping standing water practically all the time), the water table (the level beneath the ground at which water lies after soaking into the terrain: a foot or two in low elevation, possibly higher than the terrain in a swamp near sea level, dozens or hundreds of feet in high elevation without a large fresh-water body, greatly varying in a desert), the non-absorbent exception (rocky mountains, frozen ground), the dig-for-water chance (DM-determined by terrain and elevation, the desert exception) and vegetation as a water source (the subtropical and tropical water-storing plants, the cactus, the drought plains and hills, the DM availability and quantity ruling), printed p. 59 with the water-table material on p. 60.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 468,
  "prefix" = "wwf",
  "banner" = {
      "title" = "R468: the WSG WHERE WATER IS FOUND slice - the standing-water basis (the table chance models a sizable quantity of standing water, not large enough for a lake or pond: an uncharted pool, a small depression or basin holding rainstorm water not yet evaporated or absorbed), the drought reduction (no rain for several days lets the DM cut the find chance: a flat plain completely dried out, a swamp keeping standing water practically all the time), the water table (the level beneath the ground at which water lies after soaking into the terrain: a foot or two in low elevation, possibly higher than the terrain in a swamp near sea level, dozens or hundreds of feet in high elevation without a large fresh-water body, greatly varying in a desert), the non-absorbent exception (rocky mountains, frozen ground), the dig-for-water chance (DM-determined by terrain and elevation, the desert exception) and vegetation as a water source (the subtropical and tropical water-storing plants, the cactus, the drought plains and hills, the DM availability and quantity ruling), printed p. 59 with the water-table material on p. 60.",
      "provenance" = "Ground truth two-way, pure prose: the user-run tesseract text of printed p. 59 (the --psm 4 run from the R467 extraction) vs the djvu word layer (Guide_0059 tail and Guide_0060). The two readers agree on every mechanic and every number. The section heading sits at the bottom of the printed p. 59 right column; the prose continues onto printed p. 60, ending at the WATER IN THE DESERT heading. The permafrost discussion (printed p. 60, referenced by the frozen-ground exception in the water-table paragraph) is deferred to the next round with the desert material. The bad-water warning (the vegetation-free waterhole with skeletal remains) belongs to the tainted-water text and stays unpinned this round.",
      "sentinel" = "No printed grid in this slice - the standing-water basis, the drought reduction, the water-table depth rules and the vegetation source pin as consts and bools, every one audit-verified against the model.",
    },
  "consts" = { {
      "name" = "wwfLowElevMinFt",
      "value" = 1,
      "comment" = "in an area of low elevation the water table may be only a foot or two beneath the ground: the minimum depth in feet",
    }, {
      "name" = "wwfLowElevMaxFt",
      "value" = 2,
      "comment" = "the low-elevation water-table depth: the maximum in feet (a foot or two)",
    }, {
      "name" = "wwfHighElevMinFt",
      "value" = 24,
      "comment" = "in high elevation with no large body of fresh water the water table may be dozens of feet beneath the surface: the dozens floor (2d12, 24 feet, the model floor)",
    }, {
      "name" = "wwfHighElevMaxFt",
      "value" = 100,
      "comment" = "the high-elevation water table may be dozens or even hundreds of feet beneath the surface: the hundreds floor (100 feet)",
    } },
  "bools" = { {
      "name" = "wwfStandingWaterBasis",
      "value" = true,
      "comment" = "the Table 34 chance models a sizable quantity of standing water - not large enough to qualify as a lake or pond: an uncharted pool, or a small depression or basin holding rainstorm water not yet evaporated or absorbed",
    }, {
      "name" = "wwfDroughtDMReduction",
      "value" = true,
      "comment" = "if no rain has fallen for several days, the DM may reduce the chance of finding standing water in certain terrains",
    }, {
      "name" = "wwfFlatPlainDriesOut",
      "value" = true,
      "comment" = "a flat plain may be completely dried out after a few days without precipitation",
    }, {
      "name" = "wwfSwampAlwaysStanding",
      "value" = true,
      "comment" = "a swampy area will have standing water practically all the time regardless of how long since the last rain",
    }, {
      "name" = "wwfTableIsUndergroundLevel",
      "value" = true,
      "comment" = "the water table is the level beneath the ground at which water lies after soaking into the terrain - not the Chance of Finding Water Table",
    }, {
      "name" = "wwfSwampTableAboveTerrain",
      "value" = true,
      "comment" = "in a swamp, where elevation is close to sea level, the water table may actually be higher than the terrain",
    }, {
      "name" = "wwfDesertTableVaries",
      "value" = true,
      "comment" = "in the almost moisture-free desert environment the location of the water table varies greatly (the desert exception, detailed in its own section)",
    }, {
      "name" = "wwfTableNonexistentNonabsorbent",
      "value" = true,
      "comment" = "the water table is nonexistent where the terrain is not absorbent: a rocky mountain range with little or no loose soil, or frozen ground",
    }, {
      "name" = "wwfDigChanceAfterSurfaceFail",
      "value" = true,
      "comment" = "characters who fail to locate surface water on terrain where underground water may exist can be allowed a chance to find water by digging down a certain distance",
    }, {
      "name" = "wwfDigDepthDMRuling",
      "value" = true,
      "comment" = "whether underground water exists and how far down it lies are DM determinations based on the terrain and elevation; deserts are the exception with their own rules",
    }, {
      "name" = "wwfVegetationWaterSource",
      "value" = true,
      "comment" = "vegetation is another natural source of water, particularly in hot climates where many plants store fresh water inside their stems or branches as a safeguard against a dry spell",
    }, {
      "name" = "wwfCactusStoresWater",
      "value" = true,
      "comment" = "the cactus plant ability to store water inside itself has kept many desert travelers from dying of thirst",
    }, {
      "name" = "wwfDroughtPlantsOnPlainsHills",
      "value" = true,
      "comment" = "other water-storing plants not necessarily found in the desert may keep adventurers fortified on plains or in hilly areas during a drought",
    }, {
      "name" = "wwfPlantQuantityDMRuling",
      "value" = true,
      "comment" = "the DM decides whether water-bearing plants are readily available and how much water they provide",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "note" = "the low-elevation water table: a foot or two beneath the ground",
      "expr" = "m['wwfLowElevMinFt']() != 1 or m['wwfLowElevMaxFt']() != 2 or m['wwfLowElevMinFt']() >= m['wwfLowElevMaxFt']()",
    }, {
      "note" = "the high-elevation water table: dozens or even hundreds of feet beneath the surface",
      "expr" = "m['wwfHighElevMinFt']() != 24 or m['wwfHighElevMaxFt']() != 100 or m['wwfHighElevMinFt']() >= m['wwfHighElevMaxFt']()",
    }, {
      "note" = "the depth ladder climbs from the low-elevation band to the high-elevation band",
      "expr" = "m['wwfLowElevMaxFt']() >= m['wwfHighElevMinFt']()",
    }, {
      "note" = "the standing-water basis: not a lake or pond, an uncharted pool or a rain-caught depression",
      "expr" = "m['wwfStandingWaterBasis']() != 1",
    }, {
      "note" = "the drought contrast: the flat plain dries out, the swamp never does",
      "expr" = "m['wwfFlatPlainDriesOut']() != 1 or m['wwfSwampAlwaysStanding']() != 1 or m['wwfDroughtDMReduction']() != 1",
    }, {
      "note" = "the non-absorbent exception and the dig-for-water chance",
      "expr" = "m['wwfTableNonexistentNonabsorbent']() != 1 or m['wwfDigChanceAfterSurfaceFail']() != 1 or m['wwfDigDepthDMRuling']() != 1",
    }, {
      "note" = "the vegetation source: the water-storing plants, the cactus and the DM quantity ruling",
      "expr" = "m['wwfVegetationWaterSource']() != 1 or m['wwfCactusStoresWater']() != 1 or m['wwfDroughtPlantsOnPlainsHills']() != 1 or m['wwfPlantQuantityDMRuling']() != 1",
    }, {
      "note" = "the swamp anomaly: the water table above the terrain, near sea level",
      "expr" = "m['wwfSwampTableAboveTerrain']() != 1",
    } },
  "audit" = {
      "label" = "R468 WSG where water pin audit",
      "comment" = "The standing-water basis and the drought reduction (the flat plain dried out, the swamp always stocked), the water-table depth rules (the foot-or-two low elevation, the swamp table above the terrain, the dozens to hundreds of feet in high elevation), the non-absorbent exception, the dig-for-water chance and the vegetation source (the water-storing plants, the cactus, the DM quantity ruling) - every const and bool verified against the model.",
    },
}
