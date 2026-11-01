-- wds: promoted from tools/spec_r469.json (the R469: the WSG WATER IN THE DESERT slice with the PERMAFROST discussion - the desert mechanics (the desert the most arid terrain with pitifully little rainfall, the rainfall quickly lost to evaporation in hot climates or to absorption where the ground is sandy or composed of loose soil and small rocks), the underground recovery (some of the water that gets into the ground stays there and can be recovered with effort, perhaps some skill and more than a little bit of luck), the dig chance (at any given desert location a 40% chance that water lies 5-15 feet - 2d6+3 - beneath the surface and a 60% chance of finding no water no matter how deep the party digs, a character with the desert survival proficiency raising the find chance from 40% to 80%, only two tries in any 24-hour period as with any other attempt at finding water) and the permafrost mechanics (the subarctic warm-season condition with the temperature above freezing at least during daylight hours, the soil thawing to a depth of several inches and small vegetation taking root on the released water, the thin layer of arable soil over permanently frozen subsoil, permafrost a dependable source of water, the harvest technique: remove the upper layer of soil, chop out the iced-up soil beneath it and expose it to heat, the soil and the sediment settling to the bottom when the ice melts and the water poured off), printed p. 60 with the harvest seam running from the p. 59 right-column tail onto p. 60.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 469,
  "prefix" = "wds",
  "banner" = {
      "title" = "R469: the WSG WATER IN THE DESERT slice with the PERMAFROST discussion - the desert mechanics (the desert the most arid terrain with pitifully little rainfall, the rainfall quickly lost to evaporation in hot climates or to absorption where the ground is sandy or composed of loose soil and small rocks), the underground recovery (some of the water that gets into the ground stays there and can be recovered with effort, perhaps some skill and more than a little bit of luck), the dig chance (at any given desert location a 40% chance that water lies 5-15 feet - 2d6+3 - beneath the surface and a 60% chance of finding no water no matter how deep the party digs, a character with the desert survival proficiency raising the find chance from 40% to 80%, only two tries in any 24-hour period as with any other attempt at finding water) and the permafrost mechanics (the subarctic warm-season condition with the temperature above freezing at least during daylight hours, the soil thawing to a depth of several inches and small vegetation taking root on the released water, the thin layer of arable soil over permanently frozen subsoil, permafrost a dependable source of water, the harvest technique: remove the upper layer of soil, chop out the iced-up soil beneath it and expose it to heat, the soil and the sediment settling to the bottom when the ice melts and the water poured off), printed p. 60 with the harvest seam running from the p. 59 right-column tail onto p. 60.",
      "provenance" = "Ground truth two-way, pure prose: the user-run tesseract text of printed p. 60 (the --psm 4 run) vs the pdf embedded text layer (pdftotext -layout, pdf page 61). The archive.org djvu item went dark this round, so the pdf text layer stands in as the second reader. The two readers agree on every mechanic and every number: the 40/60 split, the 5-15 foot depth band, the 2d6+3 dice formula, the 80% proficiency boost, the two-tries limit and the permafrost definition. No contested cells - the user read no physical pages this round. The permafrost harvest sentence seamed from the p. 59 right-column tail (chop out) onto the p. 60 top right (the iced-up soil beneath it ... poured off); both halves verified in both readers. The permafrost definition section sits in the p. 60 left column, between the desert text and the page foot. PURIFYING WATER and the tainted-water effects (the 10% boil-taint remainder, the 2-5 round boil, the elevation evaporation ladder, the 6-hour mild and 18-hour severe minimum durations) are DEFERRED to the next round with the skeletal-remains waterhole warning.",
      "sentinel" = "No printed grid in this slice - the desert dig chances and the permafrost mechanics pin as consts and bools, every one audit-verified against the model.",
    },
  "consts" = { {
      "name" = "wdsDigFindPct",
      "value" = 40,
      "comment" = "at any given location in the desert there is a 40% chance that water lies 5-15 feet beneath the surface",
    }, {
      "name" = "wdsNoWaterPct",
      "value" = 60,
      "comment" = "the complement: a 60% chance that characters will find no water no matter how deep they dig",
    }, {
      "name" = "wdsProfFindPct",
      "value" = 80,
      "comment" = "if the party includes a character with proficiency in desert survival, the chance of him finding water is 80% instead of 40%",
    }, {
      "name" = "wdsDepthMinFt",
      "value" = 5,
      "comment" = "the desert water lies 5-15 feet (2d6+3) beneath the surface: the minimum depth in feet (the dice floor, 2+3)",
    }, {
      "name" = "wdsDepthMaxFt",
      "value" = 15,
      "comment" = "the desert depth band: the maximum in feet (the dice ceiling, 12+3)",
    } },
  "bools" = { {
      "name" = "wdsMostAridTerrain",
      "value" = true,
      "comment" = "deserts are the most arid types of terrain; they receive pitifully little rainfall",
    }, {
      "name" = "wdsRainfallLostQuickly",
      "value" = true,
      "comment" = "the rainfall that does come down is quickly lost to evaporation in hot climates or to absorption where the ground is sandy or composed of loose soil and small rocks",
    }, {
      "name" = "wdsSomeWaterStaysRecoverable",
      "value" = true,
      "comment" = "but some of the water that gets into the ground stays there, and can be recovered with effort, perhaps some skill, and more than a little bit of luck",
    }, {
      "name" = "wdsTwoTriesPerDay",
      "value" = true,
      "comment" = "as with any other attempt at finding water, only two tries can be made in any 24-hour period",
    }, {
      "name" = "wdsDesertSurvivalProfBoost",
      "value" = true,
      "comment" = "a character with proficiency in desert survival raises the find chance from 40% to 80% (see the Wilderness Proficiencies section)",
    }, {
      "name" = "wdsPermafrostSubarcticWarmSeason",
      "value" = true,
      "comment" = "permafrost is a condition found in subarctic climates during the warm season, whenever the actual temperature is generally above freezing at least during daylight hours",
    }, {
      "name" = "wdsSoilThawsSeveralInches",
      "value" = true,
      "comment" = "the soil thaws out to a depth of several inches below the surface, enabling small vegetation to take root and thrive on the water released when the soil is warmed to an above-freezing temperature",
    }, {
      "name" = "wdsPermafrostFrozenSubsoil",
      "value" = true,
      "comment" = "beneath the thin layer of arable soil is permafrost - permanently frozen subsoil",
    }, {
      "name" = "wdsPermafrostDependableSource",
      "value" = true,
      "comment" = "permafrost is a dependable source of water; all characters have to do is remove the upper layer of soil and chop out the iced-up soil beneath it",
    }, {
      "name" = "wdsPermafrostHarvestTechnique",
      "value" = true,
      "comment" = "expose the chopped-out iced-up soil to heat; when the ice melts, the soil and most large particles of sediment settle to the bottom of the container, and the water can be poured off",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "note" = "the desert depth band: 5-15 feet (2d6+3) beneath the surface",
      "expr" = "m['wdsDepthMinFt']() != 5 or m['wdsDepthMaxFt']() != 15 or m['wdsDepthMinFt']() >= m['wdsDepthMaxFt']()",
    }, {
      "note" = "the find split: the 40% dig chance and its 60% no-water complement",
      "expr" = "m['wdsDigFindPct']() != 40 or m['wdsNoWaterPct']() != 60 or m['wdsDigFindPct']() + m['wdsNoWaterPct']() != 100",
    }, {
      "note" = "the desert survival proficiency ladder: 80% instead of 40%",
      "expr" = "m['wdsProfFindPct']() != 80 or m['wdsProfFindPct']() <= m['wdsDigFindPct']()",
    }, {
      "note" = "the desert water economy: the rainfall lost quickly, some water staying recoverable",
      "expr" = "m['wdsMostAridTerrain']() != 1 or m['wdsRainfallLostQuickly']() != 1 or m['wdsSomeWaterStaysRecoverable']() != 1",
    }, {
      "note" = "the two-tries limit and the proficiency boost",
      "expr" = "m['wdsTwoTriesPerDay']() != 1 or m['wdsDesertSurvivalProfBoost']() != 1",
    }, {
      "note" = "the permafrost definition: the subarctic warm season, the several-inch thaw, the frozen subsoil",
      "expr" = "m['wdsPermafrostSubarcticWarmSeason']() != 1 or m['wdsSoilThawsSeveralInches']() != 1 or m['wdsPermafrostFrozenSubsoil']() != 1",
    }, {
      "note" = "the permafrost harvest: the dependable source and the melt-and-pour technique",
      "expr" = "m['wdsPermafrostDependableSource']() != 1 or m['wdsPermafrostHarvestTechnique']() != 1",
    } },
  "audit" = {
      "label" = "R469 WSG water in the desert pin audit",
      "comment" = "The desert dig (the 40/60 find split, the 5-15 foot depth band, the desert survival proficiency boost to 80%, the two-tries limit), the desert water economy (the rainfall lost quickly, some water staying recoverable) and the permafrost mechanics (the subarctic warm-season condition, the several-inch thaw, the frozen subsoil, the dependable source, the melt-and-pour harvest) - every const and bool verified against the model.",
    },
}
