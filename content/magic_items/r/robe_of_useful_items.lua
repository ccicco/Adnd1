-- misc magic item def: robe_of_useful_items
-- promoted from the III.E explanation prose part headers:
--   rules/dmg/miscmagic_prose_part21.h (R277)
-- The part headers remain in rules/dmg/ as the
-- print-fidelity record. DO NOT hand-edit this file; the
-- part header pins are the adjudicated record.
-- (tools/miscmagic2lua.py is the only writer.)
return {
  key = "robe_of_useful_items",
  name = "Robe of Useful Items",
  rows = {
    { name = "Robe of Useful Items",
      set = "kMisc5", band = { 12, 19 }, xp = 1500, xp_hi = 0,
      gp = 15000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 21, round = 277 },
  },
  pins = {
    { name = "usefulDetachRounds", value = 1,
      comment = "detach any 1 of the patches in 1 round" },
    { name = "usefulBaseEach", value = 2,
      comment = "always 2 each of the base patches" },
    { name = "usefulBaseCount", value = 6,
      comment = "the six base patch kinds (3 table rows)" },
    { name = "usefulExtraMin", value = 4,
      comment = "4-16 extra items which must be diced for" },
    { name = "usefulExtraMax", value = 16,
      comment = "the extra item ceiling" },
    { name = "usefulGpBag", value = 100,
      comment = "bag of 100 gold pieces" },
    { name = "usefulCofferGp", value = 500,
      comment = "the silver coffer: 500 g.p. value" },
    { name = "usefulGemsCount", value = 10,
      comment = "gems, 10 of" },
    { name = "usefulGemValueGp", value = 100,
      comment = "100 gold piece value each" },
    { name = "usefulLadderFeet", value = 24,
      comment = "wooden ladder, 24 feet long" },
    { name = "usefulPitCubicFeet", value = 10,
      comment = "pit, 10 cubic feet, open" },
    { name = "usefulRowboatFeet", value = 12,
      comment = "rowboat, 12 feet long" },
    { name = "usefulWindowWidthFeet", value = 2,
      comment = "window, 2 feet wide" },
    { name = "usefulWindowHeightFeet", value = 4,
      comment = "4 feet high" },
    { name = "usefulWindowDepthFeet", value = 2,
      comment = "up to 2 feet deep" },
    { name = "usefulScrollSpells", value = 1,
      comment = "scroll of 1 spell" },
    { name = "usefulWarDogsPair", value = 2,
      comment = "war dogs, pair" },
  },
  tables = {
    { name = "usefulRowLo",
      comment = "the printed extra item band lower edges",
      clamp_hi = 12,
      values = {
        1, 9, 16, 23, 31, 45, 52, 60, 69, 76, 84, 91, 97,
      } },
    { name = "usefulRowHi",
      comment = "the printed extra item band upper edges",
      clamp_hi = 12,
      values = {
        8, 15, 22, 30, 44, 51, 59, 68, 75, 83, 90, 96, 100,
      } },
  },
}
