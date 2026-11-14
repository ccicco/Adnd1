-- ranger_slots
-- The R1048 straggler de-wire. The ranger spell slots
-- The accessor and the clamp semantics live in
-- the source header and are unchanged.
-- DO NOT hand-edit: tools/r1048_splice.py is
-- the only writer.

return {
  key = "ranger_slots",
  name = "The ranger spell slots (10 x 5)",
  sources = {
    { part = 0, round = 1048 },
  },
  pins = {
    { name = "ranger_slotsRowCount", value = 10, comment = "the class levels" },
    { name = "ranger_slotsColCount", value = 5, comment = "the spell levels" },
  },
  tables = {
    { name = "grid", values = {
      1, 0, 0, 0, 0, 
      1, 0, 0, 1, 0, 
      2, 0, 0, 1, 0, 
      2, 0, 0, 2, 0, 
      2, 1, 0, 2, 1, 
      2, 1, 0, 2, 1, 
      2, 2, 0, 2, 2, 
      2, 2, 0, 2, 2, 
      2, 2, 1, 2, 2, 
      2, 2, 2, 2, 2, 
    } },
  },
}
