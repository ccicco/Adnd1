-- dm_sage_knowing
-- The R1054 sage de-wire (the DMG sage subsection).
-- DMG sage chance of knowing an answer (scope x nature).
-- rows[]: the four question scopes (0 out of fields, 1 minor field, 2 major field, 3 special category), names COMPUTED from the parsed clamp bounds - the R1042 equipment rows idiom.
-- tables[]: the [4][3] grids FLATTENED scope-major; the accessor reads values[scope * 3 + nature], and cell (0,2) pins the print dash -1.
-- DO NOT hand-edit: tools/r1054_splice.py is the only writer.

return {
  key = "dm_sage_knowing",
  name = "DMG sage chance of knowing an answer (scope x nature)",
  sources = {
    { part = 0, round = 1054 },
  },
  pins = {
    { name = "dm_sage_knowingRowCount",
      value = 4,
      comment = "the table rows" },
  },
  rows = {
    { name = "scope_0",
      set = "dm_sage_knowing",
      band = { 0, 0 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "scope_1",
      set = "dm_sage_knowing",
      band = { 1, 1 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "scope_2",
      set = "dm_sage_knowing",
      band = { 2, 2 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
    { name = "scope_3",
      set = "dm_sage_knowing",
      band = { 3, 3 },
      xp = 0, xp_hi = 0, gp = 0, gp_hi = 0,
      qty = { 0, 0 } },
  },
  tables = {
    { name = "know_lo",
      values = {
        31, 11, -1, 46, 31, 11, 61, 57, 26, 81, 
        76, 61, 
      },
      comment = "the knowing percent band low (scope-major flat)" },
    { name = "know_hi",
      values = {
        50, 20, -1, 65, 40, 20, 80, 60, 35, 100, 
        96, 80, 
      },
      comment = "the knowing percent band high (scope-major flat)" },
  },
}
