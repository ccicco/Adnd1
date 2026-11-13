-- misc magic item def: bag_of_transmuting
-- promoted from the III.E explanation prose part headers:
--   boneyard/dmg/miscmagic_prose_part2.h (R258)
-- The part headers remain in boneyard/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "bag_of_transmuting",
  name = "Bag of Transmuting",
  rows = {
    { name = "Bag of Transmuting",
      set = "kMisc1", band = { 27, 27 }, xp = 0, xp_hi = 0,
      gp = 500, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 2, round = 258 },
  },
  pins = {
    { name = "transmutingDisguiseQualityCount", value = 4,
      comment = "appears as one of the 4 quality types" },
    { name = "transmutingProperUsesMin", value = 2,
      comment = "performs properly for 2-5 uses" },
    { name = "transmutingProperUsesMax", value = 5,
      comment = "the top of the 2-5 use range" },
    { name = "transmutingTransmuteKindCount", value = 2,
      comment = "precious metals and gems to no worth" },
    { name = "transmutingItemBaseMaterialCount", value = 3,
      comment = "magic items to lead, glass or wood" },
    { name = "transmutingExemptKindCount", value = 2,
      comment = "artifacts and relics exempt" },
  },
  tables = {
  },
}
