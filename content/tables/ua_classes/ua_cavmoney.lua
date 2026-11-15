-- ua_cavmoney
-- The R1056 UA classes-family de-wire (rules/ua).
-- UA cavalier starting money by station.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1056_splice.py is the only writer.

return {
  key = "ua_cavmoney",
  name = "UA cavalier starting money by station",
  sources = {
    { part = 0, round = 1056 },
  },
  pins = {
    { name = "ua_cavmoneyRowCount",
      value = 6,
      comment = "the table rows" },
  },
  rows = {
    { name = "Lower Middle Class or less",
      set = "ua_cavmoney",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Middle Middle Class",
      set = "ua_cavmoney",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Upper Middle Class",
      set = "ua_cavmoney",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Lower Upper Class",
      set = "ua_cavmoney",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Middle Upper Class",
      set = "ua_cavmoney",
      band = { 4, 4 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Upper Upper Class",
      set = "ua_cavmoney",
      band = { 5, 5 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "dice_bonus",
      values = {
        0, 0, 0, 6, 6, 12, 
      },
      comment = "the UA cavalier starting money by station dice_bonus column" },
    { name = "dice_count",
      values = {
        0, 0, 0, 1, 1, 1, 
      },
      comment = "the UA cavalier starting money by station dice_count column" },
    { name = "dice_faces",
      values = {
        0, 0, 0, 12, 6, 6, 
      },
      comment = "the UA cavalier starting money by station dice_faces column" },
    { name = "gold_high",
      values = {
        80, 80, 80, 180, 180, 180, 
      },
      comment = "the UA cavalier starting money by station gold_high column" },
    { name = "gold_low",
      values = {
        20, 20, 20, 70, 70, 130, 
      },
      comment = "the UA cavalier starting money by station gold_low column" },
    { name = "item_count",
      values = {
        3, 4, 4, 6, 6, 7, 
      },
      comment = "the UA cavalier starting money by station item_count column" },
    { name = "item_offset",
      values = {
        0, 3, 7, 11, 17, 23, 
      },
      comment = "the computed prefix-sum offsets" },
  },
}
