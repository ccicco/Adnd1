-- misc magic item def: horn_of_collapsing
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part13.h (R269)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "horn_of_collapsing",
  name = "Horn of Collapsing",
  rows = {
    { name = "Horn of Collapsing",
      set = "kMisc3", band = { 49, 49 }, xp = 1500, xp_hi = 0,
      gp = 25000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 13, round = 269 },
  },
  pins = {
    { name = "hornCollapseMisfirePct", value = 10,
      comment = "sounded without the proper rune, or 10 percent of the "
      .. "time in any event" },
    { name = "hornCollapseOutRocksMin", value = 2,
      comment = "outside: a rain of fist-sized rocks" },
    { name = "hornCollapseOutRocksMax", value = 12,
      comment = "from 2-12 in number" },
    { name = "hornCollapseOutRockDmgMin", value = 1,
      comment = "each rock causes 1-6 hit points of damage" },
    { name = "hornCollapseOutRockDmgMax", value = 6,
      comment = "the 1-6 upper edge" },
    { name = "hornCollapseIndoorDmgMin", value = 3,
      comment = "indoors: the ceiling collapses on the character" },
    { name = "hornCollapseIndoorDmgMax", value = 36,
      comment = "3-36 hit points of damage" },
    { name = "hornCollapseUnderDmgMin", value = 5,
      comment = "underground: the material above falls" },
    { name = "hornCollapseUnderDmgMax", value = 20,
      comment = "5-20 hit points base damage" },
    { name = "hornCollapseUnderHeightFactorFeet", value = 10,
      comment = "the base damage is multiplied by 1 factor for each 10 "
      .. "feet of drop height (twice at 20 feet, three times at "
      .. "30 feet, etc.)" },
    { name = "hornCollapseAimRangeMinFeet", value = 30,
      comment = "proper use: point at the roof overhead from" },
    { name = "hornCollapseAimRangeMaxFeet", value = 60,
      comment = "30 to 60 feet beyond the user" },
    { name = "hornCollapseRoofWidthFeet", value = 20,
      comment = "collapses a roof section up to 20 feet wide" },
    { name = "hornCollapseRoofLengthFeet", value = 20,
      comment = "and 20 feet long" },
    { name = "hornCollapseRoofRadiusFeet", value = 10,
      comment = "a 10 feet radius from the central aiming point" },
    { name = "hornCollapseIndoorsOrUndergroundOnly", value = 1,
      comment = "the aimed collapse inflicts damage only if indoors or "
      .. "underground" },
  },
  tables = {
  },
}
