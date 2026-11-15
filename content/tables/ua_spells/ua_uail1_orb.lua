-- ua_uail1_orb
-- The R1057 UA spells-family de-wire (rules/ua).
-- UA orb of color ladder.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1057_splice.py is the only writer.

return {
  key = "ua_uail1_orb",
  name = "UA orb of color ladder",
  sources = {
    { part = 0, round = 1057 },
  },
  pins = {
    { name = "ua_uail1_orbRowCount",
      value = 9,
      comment = "the table rows" },
  },
  rows = {
    { name = "Pearly",
      set = "ua_uail1_orb",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Ruby",
      set = "ua_uail1_orb",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Flame",
      set = "ua_uail1_orb",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Amber",
      set = "ua_uail1_orb",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Emerald",
      set = "ua_uail1_orb",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Turquoise",
      set = "ua_uail1_orb",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Sapphire",
      set = "ua_uail1_orb",
      band = { 6, 6 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Amethyst",
      set = "ua_uail1_orb",
      band = { 7, 7 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Ashen",
      set = "ua_uail1_orb",
      band = { 8, 8 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "orb_damage_max",
      values = {
        4, 6, 8, 10, 12, 16, 8, 0, 0, 
      },
      comment = "the UA orb of color ladder orb_damage_max column" },
    { name = "orb_damage_min",
      values = {
        1, 1, 1, 1, 1, 2, 2, 0, 0, 
      },
      comment = "the UA orb of color ladder orb_damage_min column" },
    { name = "orb_level",
      values = {
        1, 2, 3, 4, 5, 6, 7, 10, 12, 
      },
      comment = "the UA orb of color ladder orb_level column" },
  },
}
