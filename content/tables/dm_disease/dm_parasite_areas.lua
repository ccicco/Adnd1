-- dm_parasite_areas
-- The R1051 disease de-wire (DMG pp.13-14).
-- DMG p.14 parasitic infestation table (6 areas).
-- rows[]: the printed area names (name the
-- string, band the row index, the price/xp/
-- qty keys all 0 - the R1042 equipment
-- rows idiom). tables[]: the d100 band lows,
-- the occurrence and severity d8 highs,
-- the severity d8 highs.
-- The accessors live in rules/dmg/disease.h
-- and are unchanged.
-- DO NOT hand-edit: tools/r1051_splice.py
-- is the only writer.

return {
  key = "dm_parasite_areas",
  name = "DMG p.14 parasitic infestation table (6 areas)",
  sources = {
    { part = 0, round = 1051 },
  },
  pins = {
    { name = "dm_parasite_areasRowCount",
      value = 6,
      comment = "the table rows" },
  },
  rows = {
    { name = "cardiovascular system",
      set = "dm_parasite_areas",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "intestines",
      set = "dm_parasite_areas",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "muscles",
      set = "dm_parasite_areas",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "respiratory system",
      set = "dm_parasite_areas",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "skin/hair",
      set = "dm_parasite_areas",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "stomach",
      set = "dm_parasite_areas",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "d100",
      values = {
        1, 11, 36, 41, 46, 76, 
      },
      comment = "the d100 band lows" },
    { name = "sev_mild_hi",
      values = {
        2, 2, 1, 1, 7, 2, 
      },
      comment = "the severity d8 mild highs" },
    { name = "sev_severe_hi",
      values = {
        5, 7, 3, 4, 8, 7, 
      },
      comment = "the severity d8 severe highs" },
    { name = "sev_terminal_hi",
      values = {
        8, 8, 8, 8, 0, 8, 
      },
      comment = "the severity d8 terminal highs" },
  },
}
