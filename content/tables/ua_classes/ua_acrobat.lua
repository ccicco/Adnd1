-- ua_acrobat
-- The R1056 UA classes-family de-wire (rules/ua).
-- UA thief-acrobat Function Table and skill pins.
-- rows[]: the def's row names - the R1042 equipment rows idiom (computed names where the print has no name list).
-- tables[]: the printed columns; the accessors live in rules/ua and keep their clamps.
-- DO NOT hand-edit: tools/r1056_splice.py is the only writer.

return {
  key = "ua_acrobat",
  name = "UA thief-acrobat Function Table and skill pins",
  sources = {
    { part = 0, round = 1056 },
  },
  pins = {
    { name = "ua_acrobatRowCount",
      value = 4,
      comment = "the table rows" },
  },
  rows = {
    { name = "Find Traps",
      set = "ua_acrobat",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Pick Pockets",
      set = "ua_acrobat",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Open Locks",
      set = "ua_acrobat",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "Remove Traps",
      set = "ua_acrobat",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "carry_gp",
      values = {
        1000, -1, 0, 2000, 1000, -1, 0, 2000, 1000, 3000, 
        2000, 1000, 4000, 3000, 2000, 
      },
      comment = "the UA thief-acrobat Function Table and skill pins carry_gp column; [a][b] FLATTENED a-major, width 3" },
    { name = "dex_attack",
      values = {
        1, 2, 3, 4, 
      },
      comment = "the UA thief-acrobat Function Table and skill pins dex_attack column; dex band 16-19 reads arg - 16" },
    { name = "dex_evasion",
      values = {
        2, 3, 5, 8, 
      },
      comment = "the UA thief-acrobat Function Table and skill pins dex_evasion column; dex band 16-19 reads arg - 16" },
    { name = "dex_falling",
      values = {
        0, 0, 5, 10, 
      },
      comment = "the UA thief-acrobat Function Table and skill pins dex_falling column; dex band 16-19 reads arg - 16" },
    { name = "dex_tightrope",
      values = {
        5, 10, 15, 20, 
      },
      comment = "the UA thief-acrobat Function Table and skill pins dex_tightrope column; dex band 16-19 reads arg - 16" },
    { name = "dex_vault",
      values = {
        0, 5, 10, 15, 
      },
      comment = "the UA thief-acrobat Function Table and skill pins dex_vault column; dex band 16-19 reads arg - 16" },
    { name = "ext_fail",
      values = {
        0, 25, 50, 75, 
      },
      comment = "the UA thief-acrobat Function Table and skill pins ext_fail column" },
    { name = "ext_recover",
      values = {
        2, 3, 4, 5, 
      },
      comment = "the UA thief-acrobat Function Table and skill pins ext_recover column" },
    { name = "fall_known",
      values = {
        6, 10, 25, 7, 10, 50, 8, 10, 75, 9, 
        10, 100, 9, 20, 25, 13, 30, 50, 14, 30, 
        75, 15, 40, 20, 16, 40, 40, 17, 40, 60, 
        18, 40, 80, 19, 50, 20, 20, 50, 40, 21, 
        50, 60, 22, 50, 80, 23, 50, 100, 23, 60, 
        20, 
      },
      comment = "the UA thief-acrobat Function Table and skill pins fall_known column; the [17][3] search triples flat" },
    { name = "split_xp",
      values = {
        20000, 45000, 75000, 125000, 180000, 250000, 500000, 
      },
      comment = "the UA thief-acrobat Function Table and skill pins split_xp column; banded reads index arg - 6" },
  },
}
