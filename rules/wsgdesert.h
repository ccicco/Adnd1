// =========================================================================================
// Adnd1 - rules/wsgdesert.h
// R469: the WSG WATER IN THE DESERT slice with the PERMAFROST discussion -
// the desert mechanics (the desert the most arid terrain with pitifully
// little rainfall, the rainfall quickly lost to evaporation in hot climates
// or to absorption where the ground is sandy or composed of loose soil and
// small rocks), the underground recovery (some of the water that gets into
// the ground stays there and can be recovered with effort, perhaps some skill
// and more than a little bit of luck), the dig chance (at any given desert
// location a 40% chance that water lies 5-15 feet - 2d6+3 - beneath the
// surface and a 60% chance of finding no water no matter how deep the party
// digs, a character with the desert survival proficiency raising the find
// chance from 40% to 80%, only two tries in any 24-hour period as with any
// other attempt at finding water) and the permafrost mechanics (the subarctic
// warm-season condition with the temperature above freezing at least during
// daylight hours, the soil thawing to a depth of several inches and small
// vegetation taking root on the released water, the thin layer of arable soil
// over permanently frozen subsoil, permafrost a dependable source of water,
// the harvest technique: remove the upper layer of soil, chop out the iced-up
// soil beneath it and expose it to heat, the soil and the sediment settling
// to the bottom when the ice melts and the water poured off), printed p. 60
// with the harvest seam running from the p. 59 right-column tail onto p. 60.
// census 393 -> 394.
//
// Ground truth two-way, pure prose: the user-run tesseract text of printed p.
// 60 (the --psm 4 run) vs the pdf embedded text layer (pdftotext -layout, pdf
// page 61). The archive.org djvu item went dark this round, so the pdf text
// layer stands in as the second reader. The two readers agree on every
// mechanic and every number: the 40/60 split, the 5-15 foot depth band, the
// 2d6+3 dice formula, the 80% proficiency boost, the two-tries limit and the
// permafrost definition. No contested cells - the user read no physical pages
// this round. The permafrost harvest sentence seamed from the p. 59
// right-column tail (chop out) onto the p. 60 top right (the iced-up soil
// beneath it ... poured off); both halves verified in both readers. The
// permafrost definition section sits in the p. 60 left column, between the
// desert text and the page foot. PURIFYING WATER and the tainted-water
// effects (the 10% boil-taint remainder, the 2-5 round boil, the elevation
// evaporation ladder, the 6-hour mild and 18-hour severe minimum durations)
// are DEFERRED to the next round with the skeletal-remains waterhole warning.
//
// No printed grid in this slice - the desert dig chances and the permafrost
// mechanics pin as consts and bools, every one audit-verified against the
// model.
//
namespace rules {

// ---- The desert dig ----

// deserts are the most arid types of terrain; they receive pitifully little
// rainfall
inline bool wdsMostAridTerrain()
    { return true; }

// the rainfall that does come down is quickly lost to evaporation in hot
// climates or to absorption where the ground is sandy or composed of loose
// soil and small rocks
inline bool wdsRainfallLostQuickly()
    { return true; }

// but some of the water that gets into the ground stays there, and can be
// recovered with effort, perhaps some skill, and more than a little bit of
// luck
inline bool wdsSomeWaterStaysRecoverable()
    { return true; }

// at any given location in the desert there is a 40% chance that water lies
// 5-15 feet beneath the surface
inline int wdsDigFindPct()
    { return 40; }

// the complement: a 60% chance that characters will find no water no matter
// how deep they dig
inline int wdsNoWaterPct()
    { return 60; }

// the desert water lies 5-15 feet (2d6+3) beneath the surface: the minimum
// depth in feet (the dice floor, 2+3)
inline int wdsDepthMinFt()
    { return 5; }

// the desert depth band: the maximum in feet (the dice ceiling, 12+3)
inline int wdsDepthMaxFt()
    { return 15; }

// a character with proficiency in desert survival raises the find chance from
// 40% to 80% (see the Wilderness Proficiencies section)
inline bool wdsDesertSurvivalProfBoost()
    { return true; }

// if the party includes a character with proficiency in desert survival, the
// chance of him finding water is 80% instead of 40%
inline int wdsProfFindPct()
    { return 80; }

// as with any other attempt at finding water, only two tries can be made in
// any 24-hour period
inline bool wdsTwoTriesPerDay()
    { return true; }

// ---- Permafrost ----

// permafrost is a condition found in subarctic climates during the warm
// season, whenever the actual temperature is generally above freezing at
// least during daylight hours
inline bool wdsPermafrostSubarcticWarmSeason()
    { return true; }

// the soil thaws out to a depth of several inches below the surface, enabling
// small vegetation to take root and thrive on the water released when the
// soil is warmed to an above-freezing temperature
inline bool wdsSoilThawsSeveralInches()
    { return true; }

// beneath the thin layer of arable soil is permafrost - permanently frozen
// subsoil
inline bool wdsPermafrostFrozenSubsoil()
    { return true; }

// permafrost is a dependable source of water; all characters have to do is
// remove the upper layer of soil and chop out the iced-up soil beneath it
inline bool wdsPermafrostDependableSource()
    { return true; }

// expose the chopped-out iced-up soil to heat; when the ice melts, the soil
// and most large particles of sediment settle to the bottom of the container,
// and the water can be poured off
inline bool wdsPermafrostHarvestTechnique()
    { return true; }

}   // namespace rules
