-- paladin_slots
-- The R1048 straggler de-wire. The paladin clerical spell slots
-- The accessor and the clamp semantics live in
-- the source header and are unchanged.
-- DO NOT hand-edit: tools/r1048_splice.py is
-- the only writer.

return {
  key = "paladin_slots",
  name = "The paladin clerical spell slots (12 x 4)",
  sources = {
    { part = 0, round = 1048 },
  },
  pins = {
    { name = "paladin_slotsRowCount", value = 12, comment = "the class levels" },
    { name = "paladin_slotsColCount", value = 4, comment = "the spell levels" },
  },
  tables = {
    { name = "grid", values = {
      1, 0, 0, 0, 
      2, 0, 0, 0, 
      2, 1, 0, 0, 
      2, 2, 0, 0, 
      2, 2, 1, 0, 
      3, 2, 1, 0, 
      3, 2, 1, 1, 
      3, 3, 1, 1, 
      3, 3, 2, 1, 
      3, 3, 3, 1, 
      3, 3, 3, 2, 
      3, 3, 3, 3, 
    } },
  },
}
