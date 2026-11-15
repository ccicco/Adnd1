-- ua_followers
-- The R1056 UA classes-family de-wire (rules/ua).
-- UA cavalier follower dice and equipment rows.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1056_splice.py is the only writer.

return {
  key = "ua_followers",
  name = "UA cavalier follower dice and equipment rows",
  sources = {
    { part = 0, round = 1056 },
  },
  pins = {
    { name = "ua_followersRowCount",
      value = 7,
      comment = "the table rows" },
  },
  rows = {
    { name = "level_4",
      set = "ua_followers",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "level_5",
      set = "ua_followers",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "level_6",
      set = "ua_followers",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "level_7",
      set = "ua_followers",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "level_8",
      set = "ua_followers",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "level_9",
      set = "ua_followers",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "level_10",
      set = "ua_followers",
      band = { 6, 6 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "dice_count",
      values = {
        1, 2, 3, 6, 12, 24, 48, 
      },
      comment = "the UA cavalier follower dice and equipment rows dice_count column; banded reads index arg - 4" },
    { name = "equip_hi",
      values = {
        50, 75, 90, 100, 
      },
      comment = "the UA cavalier follower dice and equipment rows equip_hi column" },
    { name = "equip_lo",
      values = {
        1, 51, 76, 91, 
      },
      comment = "the UA cavalier follower dice and equipment rows equip_lo column" },
  },
}
