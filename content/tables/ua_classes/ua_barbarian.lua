-- ua_barbarian
-- The R1056 UA classes-family de-wire (rules/ua).
-- UA barbarian class tables.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1056_splice.py is the only writer.

return {
  key = "ua_barbarian",
  name = "UA barbarian class tables",
  sources = {
    { part = 0, round = 1056 },
  },
  pins = {
    { name = "ua_barbarianRowCount",
      value = 7,
      comment = "the table rows" },
  },
  rows = {
    { name = "Animal Handling",
      set = "ua_barbarian",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Horsemanship",
      set = "ua_barbarian",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Long-Distance Signaling",
      set = "ua_barbarian",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Running",
      set = "ua_barbarian",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Small Craft (Paddled and Rowed)",
      set = "ua_barbarian",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Sound Imitation",
      set = "ua_barbarian",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Snare Building",
      set = "ua_barbarian",
      band = { 6, 6 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "strike_level",
      values = {
        4, 6, 8, 10, 12, 
      },
      comment = "the UA barbarian class tables strike_level column" },
    { name = "xp_attain",
      values = {
        0, 6000, 12000, 24000, 48000, 80000, 150000, 275000, 500000, 1000000, 
        1500000, 
      },
      comment = "the UA barbarian class tables xp_attain column; banded reads index arg - 1" },
  },
}
