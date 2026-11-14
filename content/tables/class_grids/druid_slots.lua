-- class grid def: druid_slots
-- The druid spell slots grid, the R1047 de-wire.
-- Table encoding: tables[1] name "grid",
-- values = the printed slot counts flat
-- (row-major, 14 rows x 7 cols).
-- The accessor and the clamp semantics
-- live in the phb header and are unchanged.
-- DO NOT hand-edit: tools/r1047_splice.py
-- is the only writer.

return {
  key = "druid_slots",
  name = "The druid spell slots grid (14 x 7)",
  sources = {
    { part = 0, round = 1047 },
  },
  pins = {
    { name = "druid_slotsRowCount", value = 14, comment = "the class levels" },
    { name = "druid_slotsColCount", value = 7, comment = "the spell levels" },
  },
  tables = {
    { name = "grid", values = {
      2, 0, 0, 0, 0, 0, 0, 
      2, 1, 0, 0, 0, 0, 0, 
      3, 2, 1, 0, 0, 0, 0, 
      4, 2, 2, 0, 0, 0, 0, 
      4, 3, 2, 0, 0, 0, 0, 
      4, 3, 2, 1, 0, 0, 0, 
      4, 4, 3, 1, 0, 0, 0, 
      4, 4, 3, 2, 0, 0, 0, 
      5, 4, 3, 2, 1, 0, 0, 
      5, 4, 3, 3, 2, 0, 0, 
      5, 5, 3, 3, 2, 1, 0, 
      5, 5, 4, 4, 3, 2, 1, 
      6, 5, 5, 5, 4, 3, 2, 
      6, 6, 6, 6, 5, 4, 3, 
    } },
  },
}
