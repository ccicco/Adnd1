-- dm_sage_terms
-- The R1054 sage de-wire (the DMG sage subsection).
-- DMG sage support, salary, efficiency and improvement.
-- rows[]: the employment offer rows (names COMPUTED from the parsed offer bounds) - the R1042 equipment rows idiom.
-- tables[]: improve_max row 3 pins -1 (no stated maximum).
-- DO NOT hand-edit: tools/r1054_splice.py is the only writer.

return {
  key = "dm_sage_terms",
  name = "DMG sage support, salary, efficiency and improvement",
  sources = {
    { part = 0, round = 1054 },
  },
  pins = {
    { name = "dm_sage_termsRowCount",
      value = 3,
      comment = "the table rows" },
  },
  rows = {
    { name = "offer_200_1200",
      set = "dm_sage_terms",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "offer_200_1200",
      set = "dm_sage_terms",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "offer_20000_20000",
      set = "dm_sage_terms",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "offer_lo",
      values = {
        200, 200, 20000, 
      },
      comment = "the offer row low (g.p. per month)" },
    { name = "offer_hi",
      values = {
        1200, 1200, 20000, 
      },
      comment = "the offer row high (g.p. per month)" },
    { name = "eff_milestone_cost",
      values = {
        20000, 60000, 100000, 
      },
      comment = "the efficiency milestone cost (g.p.)" },
    { name = "eff_milestone_percent",
      values = {
        50, 90, 100, 
      },
      comment = "the efficiency milestone percent" },
    { name = "improve_cost",
      values = {
        5000, 10000, 100000, 200000, 
      },
      comment = "the improvement cost (g.p.)" },
    { name = "improve_months",
      values = {
        1, 1, 24, 24, 
      },
      comment = "the improvement time (months)" },
    { name = "improve_max",
      values = {
        5, 5, 3, -1, 
      },
      comment = "the improvement maximum (-1 no stated maximum)" },
  },
}
