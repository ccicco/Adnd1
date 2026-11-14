-- class ladder def: illusionist
-- The PHB class xp-title ladder, the R1044 de-wire. The six subclass ladders of rules/phb/subclasses.h.
-- Row encoding: band = { level, level } the printed
-- level, gp the XP to attain it (0 at level 1),
-- name the printed title. The accessor and clamp
-- semantics live in rules/phb/subclasses.h and are unchanged.
-- DO NOT hand-edit: tools/r1044_splice.py is the only writer.

return {
  key = "illusionist",
  name = "The illusionist xp and title ladder (12 rows)",
  rows = {
    { name = "Prestidigitator", set = "illusionist", band = { 1, 1 }, xp = 0, xp_hi = 0, gp = 0, gp_hi = 0, qty = { 0, 0 } },
    { name = "Minor Trickster", set = "illusionist", band = { 2, 2 }, xp = 0, xp_hi = 0, gp = 2250, gp_hi = 0, qty = { 0, 0 } },
    { name = "Trickster", set = "illusionist", band = { 3, 3 }, xp = 0, xp_hi = 0, gp = 4500, gp_hi = 0, qty = { 0, 0 } },
    { name = "Master Trickster", set = "illusionist", band = { 4, 4 }, xp = 0, xp_hi = 0, gp = 9000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Cabalist", set = "illusionist", band = { 5, 5 }, xp = 0, xp_hi = 0, gp = 18000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Visionist", set = "illusionist", band = { 6, 6 }, xp = 0, xp_hi = 0, gp = 35000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Phantasmist", set = "illusionist", band = { 7, 7 }, xp = 0, xp_hi = 0, gp = 60000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Apparitionist", set = "illusionist", band = { 8, 8 }, xp = 0, xp_hi = 0, gp = 95000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Spellbinder", set = "illusionist", band = { 9, 9 }, xp = 0, xp_hi = 0, gp = 145000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Illusionist", set = "illusionist", band = { 10, 10 }, xp = 0, xp_hi = 0, gp = 220000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Illusionist (11th level)", set = "illusionist", band = { 11, 11 }, xp = 0, xp_hi = 0, gp = 440000, gp_hi = 0, qty = { 0, 0 } },
    { name = "Illusionist (12th level)", set = "illusionist", band = { 12, 12 }, xp = 0, xp_hi = 0, gp = 660000, gp_hi = 0, qty = { 0, 0 } },
  },
  sources = {
    { part = 0, round = 1044 },
  },
  pins = {
    { name = "illusionistRowCount", value = 12, comment = "the printed row count" },
  },
  tables = {},
}
