-- dm_sage_characteristics
-- The R1054 sage de-wire (the DMG sage subsection).
-- DMG sage characteristics (abilities and alignment).
-- rows[]: the printed alignment bands in ascending dice order - the R1042 equipment rows idiom.
-- tables[]: the printed columns; the accessors live in rules/dmg/sage.h and keep their clamps.
-- DO NOT hand-edit: tools/r1054_splice.py is the only writer.

return {
  key = "dm_sage_characteristics",
  name = "DMG sage characteristics (abilities and alignment)",
  sources = {
    { part = 0, round = 1054 },
  },
  pins = {
    { name = "dm_sage_characteristicsRowCount",
      value = 9,
      comment = "the table rows" },
  },
  rows = {
    { name = "chaotic evil",
      set = "dm_sage_characteristics",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "chaotic good",
      set = "dm_sage_characteristics",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "chaotic neutral",
      set = "dm_sage_characteristics",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "lawful evil",
      set = "dm_sage_characteristics",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "lawful good",
      set = "dm_sage_characteristics",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "lawful neutral",
      set = "dm_sage_characteristics",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "neutral",
      set = "dm_sage_characteristics",
      band = { 6, 6 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "neutral evil",
      set = "dm_sage_characteristics",
      band = { 7, 7 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "neutral good",
      set = "dm_sage_characteristics",
      band = { 8, 8 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "align_lo",
      values = {
        1, 6, 11, 21, 31, 41, 61, 81, 91, 
      },
      comment = "the alignment band low" },
    { name = "align_hi",
      values = {
        5, 10, 20, 30, 40, 60, 80, 90, 100, 
      },
      comment = "the alignment band high" },
    { name = "ability_dice",
      values = {
        8, 4, 6, 6, 6, 6, 
      },
      comment = "the ability die (0 STR..5 CHA)" },
    { name = "ability_dice_count",
      values = {
        1, 1, 1, 3, 2, 2, 
      },
      comment = "the ability dice count (0 STR..5 CHA)" },
    { name = "ability_plus",
      values = {
        7, 14, 12, 0, 3, 2, 
      },
      comment = "the ability plus (0 STR..5 CHA)" },
  },
}
