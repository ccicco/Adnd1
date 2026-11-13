-- misc magic item def: jewel_of_flawlessness
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part16.h (R272)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "jewel_of_flawlessness",
  name = "Jewel of Flawlessness",
  rows = {
    { name = "Jewel of Flawlessness",
      set = "kMisc3", band = { 92, 92 }, xp = 0, xp_hi = 0,
      gp = 1000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 16, round = 272 },
  },
  pins = {
    { name = "jewelFlawlessBoostPct", value = 100,
      comment = "the value likelihood rises 100 percent" },
    { name = "jewelFlawlessBaseTenths", value = 1,
      comment = "1 in 10 stones rise unboosted" },
    { name = "jewelFlawlessBoostedTenths", value = 2,
      comment = "2 in 10 stones rise boosted" },
    { name = "jewelFlawlessFacetMin", value = 10,
      comment = "the jewel has 10-100 facets" },
    { name = "jewelFlawlessFacetMax", value = 100,
      comment = "the upper edge of the 10-100 facets" },
    { name = "jewelFlawlessTriggerD10", value = 2,
      comment = "a roll of 2 on d10 raises a stone" },
    { name = "jewelFlawlessFacetsLostPerBoost", value = 1,
      comment = "1 facet disappears per raised stone" },
  },
  tables = {
  },
}
