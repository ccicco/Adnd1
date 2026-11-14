-- class grid def: bard_druid_slots
-- The bard druid spell slots grid, the R1047 de-wire.
-- Table encoding: tables[1] name "grid",
-- values = the printed slot counts flat
-- (row-major, 23 rows x 5 cols).
-- The accessor and the clamp semantics
-- live in the phb header and are unchanged.
-- DO NOT hand-edit: tools/r1047_splice.py
-- is the only writer.

return {
  key = "bard_druid_slots",
  name = "The bard druid spell slots grid (23 x 5)",
  sources = {
    { part = 0, round = 1047 },
  },
  pins = {
    { name = "bard_druid_slotsRowCount", value = 23, comment = "the class levels" },
    { name = "bard_druid_slotsColCount", value = 5, comment = "the spell levels" },
  },
  tables = {
    { name = "grid", values = {
      1, 0, 0, 0, 0, 
      2, 0, 0, 0, 0, 
      3, 0, 0, 0, 0, 
      3, 1, 0, 0, 0, 
      3, 2, 0, 0, 0, 
      3, 3, 0, 0, 0, 
      3, 3, 1, 0, 0, 
      3, 3, 2, 0, 0, 
      3, 3, 3, 0, 0, 
      3, 3, 3, 1, 0, 
      3, 3, 3, 2, 0, 
      3, 3, 3, 3, 0, 
      3, 3, 3, 3, 1, 
      3, 3, 3, 3, 2, 
      3, 3, 3, 3, 3, 
      4, 3, 3, 3, 3, 
      4, 4, 3, 3, 3, 
      4, 4, 4, 3, 3, 
      5, 4, 4, 4, 3, 
      5, 4, 4, 4, 4, 
      5, 5, 4, 4, 4, 
      5, 5, 5, 4, 4, 
      5, 5, 5, 5, 5, 
    } },
  },
}
