-- dm_sage_discovery
-- The R1054 sage de-wire (the DMG sage subsection).
-- DMG sage information discovery time and cost.
-- rows[]: the four question scopes as in dm_sage_knowing (names COMPUTED from the parsed clamp bounds) - the R1042 equipment rows idiom.
-- tables[]: the time grids FLATTENED scope-major (cell (0,2) pins the print dash -1 in time_lo/time_hi).
-- DO NOT hand-edit: tools/r1054_splice.py is the only writer.

return {
  key = "dm_sage_discovery",
  name = "DMG sage information discovery time and cost",
  sources = {
    { part = 0, round = 1054 },
  },
  pins = {
    { name = "dm_sage_discoveryRowCount",
      value = 4,
      comment = "the table rows" },
  },
  rows = {
    { name = "scope_0",
      set = "dm_sage_discovery",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "scope_1",
      set = "dm_sage_discovery",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "scope_2",
      set = "dm_sage_discovery",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "scope_3",
      set = "dm_sage_discovery",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "cost_per_day",
      values = {
        100, 1000, 500, 200, 
      },
      comment = "the g.p. cost per day for the scope" },
    { name = "free_spread_percent",
      values = {
        20, 20, 20, 80, 
      },
      comment = "the free-cost spread threshold for the scope" },
    { name = "time_lo",
      values = {
        1, 2, -1, 1, 2, 5, 1, 1, 3, 1, 
        1, 2, 
      },
      comment = "the discovery time band low (scope-major flat)" },
    { name = "time_hi",
      values = {
        6, 24, -1, 4, 20, 40, 3, 12, 30, 2, 
        10, 12, 
      },
      comment = "the discovery time band high (scope-major flat)" },
    { name = "time_unit",
      values = {
        0, 2, 0, 0, 2, 2, 0, 2, 2, 0, 
        1, 2, 
      },
      comment = "the discovery time unit (scope-major flat)" },
  },
}
